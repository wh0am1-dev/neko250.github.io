#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

#define MAX 90

// ================================

int create_thread(pthread_t* thread, void* (*func)(void*), void* arg, int sched, int prio) {
	struct sched_param param = { prio };
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&attr, sched);
	pthread_attr_setschedparam(&attr, &param);
	int r = pthread_create(thread, &attr, func, arg);
	pthread_attr_destroy(&attr);
	return r;
}

int change_priority(int sched, int prio) {
	struct sched_param param = { prio };
	return pthread_setschedparam(pthread_self(), sched, &param);
}

long generate_random(pthread_mutex_t* mutex, long min, long max) {
	long r;
	pthread_mutex_lock(mutex);
	r = min + random() % (max - min + 1);
	pthread_mutex_unlock(mutex);
	return r;
}

int create_mutex(pthread_mutex_t* mutex) {
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
	int r = pthread_mutex_init(mutex, &attr);
	pthread_mutexattr_destroy(&attr);
	return r;
}

// ================================

typedef struct {
	pthread_t thread;
	pthread_mutex_t mutex;
	int interval;
	int value;
} Sensor;

typedef struct {
	pthread_t control;
	pthread_mutex_t random;
	Sensor presence;
	Sensor vibration;
	int interval;
} Control;

void* presence_task(void*);
void* vibration_task(void*);
void* control_task(void*);

// ================================

int main() {
	mlockall(MCL_CURRENT | MCL_FUTURE);
	srand(time(NULL));

	Control c;
	create_mutex(&c.presence.mutex);
	create_mutex(&c.vibration.mutex);
	pthread_mutex_init(&c.random, NULL);
	change_priority(SCHED_FIFO, 30);
	c.interval = 4;
	c.presence.interval = 2;
	c.vibration.interval = 3;

	create_thread(&c.control, control_task, &c, SCHED_FIFO, 25);
	create_thread(&c.presence.thread, presence_task, &c, SCHED_FIFO, 29);
	create_thread(&c.vibration.thread, vibration_task, &c, SCHED_FIFO, 27);

	pthread_join(c.control, NULL);
	pthread_join(c.presence.thread, NULL);
	pthread_join(c.vibration.thread, NULL);

	pthread_mutex_destroy(&c.presence.mutex);
	pthread_mutex_destroy(&c.vibration.mutex);
	pthread_mutex_destroy(&c.random);

	return 0;
}

// ================================

void* presence_task(void* arg) {
	Control* c = (Control*) arg;
	struct timespec ispec;
	clock_gettime(CLOCK_MONOTONIC, &ispec);
	ispec.tv_sec += c->presence.interval;

	while (true) {
		while (clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ispec, NULL) == EINTR);

		pthread_mutex_lock(&c->presence.mutex);

		c->presence.value = generate_random(&c->random, 0, 1);
		if (c->presence.value) {
			printf(":: possible presence ::");
		}

		pthread_mutex_unlock(&c->presence.mutex);
		ispec.tv_sec += c->presence.interval;
	}
}

// ================================

void* vibration_task(void* arg) {
	Control* c = (Control*) arg;
	struct timespec ispec;
	clock_gettime(CLOCK_MONOTONIC, &ispec);
	ispec.tv_sec += c->vibration.interval;

	while (true) {
		while (clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ispec, NULL) == EINTR);

		pthread_mutex_lock(&c->vibration.mutex);

		c->vibration.value = generate_random(&c->random, 0, MAX * 2);
		if (c->vibration.value > MAX) {
			printf(":: possible incursion ::");
		}

		pthread_mutex_unlock(&c->vibration.mutex);
		ispec.tv_sec += c->vibration.interval;
	}
}

// ================================

void* control_task(void* arg) {
	Control* c = (Control*) arg;
	struct timespec ispec;
	clock_gettime(CLOCK_MONOTONIC, &ispec);
	ispec.tv_sec += c->interval;

	long presence, vibration;
	while (true) {
		while (clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ispec, NULL) == EINTR);

		pthread_mutex_lock(&c->vibration.mutex);
		vibration = c->vibration.value;
		pthread_mutex_unlock(&c->vibration.mutex);

		pthread_mutex_lock(&c->presence.mutex);
		presence = c->presence.value;
		pthread_mutex_unlock(&c->presence.mutex);

		printf("- presence: %ld\n- vibration: %ld\n", presence, vibration);
		ispec.tv_sec += c->interval;
	}
}
