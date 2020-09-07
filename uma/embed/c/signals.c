#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

#define IN_CAR SIGRTMIN
#define IN_VAN SIGRTMIN + 1
#define OUT_CAR SIGRTMIN + 2
#define OUT_VAN SIGRTMIN + 3
#define TIMER_CAR SIGRTMIN + 4
#define TIMER_VAN SIGRTMIN + 5
#define TIMER_OUT SIGRTMIN + 6

// ================================

int create_timer(timer_t* timer, int signo) {
  struct sigevent sigev;
  sigev.sigev_notify = SIGEV_SIGNAL;
  sigev.sigev_signo = signo;
  sigev.sigev_value.sival_int = 0;

  return timer_create(CLOCK_MONOTONIC, &sigev, timer);
}

int activate_timer(timer_t timer, time_t secs, long nsec) {
  struct itimerspec itspec;
  itspec.it_interval.tv_sec = secs;
  itspec.it_interval.tv_nsec = nsec;
  itspec.it_value.tv_sec = 0;
  itspec.it_value.tv_nsec = 1;

  return timer_settime(timer, 0, &itspec, NULL);
}

long generate_random(pthread_mutex_t* mutex) {
  long r;
  pthread_mutex_lock(mutex);
  r = random() % 2;
  pthread_mutex_unlock(mutex);
  return r;
}

// ================================

typedef struct {
  pthread_t thread;
  int interval;
} Vehicle;

typedef struct {
  Vehicle car;
  Vehicle van;
  pthread_t in;
  pthread_t out;
  pthread_mutex_t random;
  pthread_mutex_t mutex;
  int interval;
  int cars;
  int vans;
} Control;

sigset_t sigset;
void* car_task(void*);
void* van_task(void*);
void* in_task(void*);
void* out_task(void*);

// ================================

int main() {
  mlockall(MCL_CURRENT | MCL_FUTURE);
  srandom(time(NULL));
  sigemptyset(&sigset);
  sigaddset(&sigset, IN_CAR);
  sigaddset(&sigset, IN_VAN);
  sigaddset(&sigset, OUT_CAR);
  sigaddset(&sigset, OUT_VAN);
  sigaddset(&sigset, TIMER_CAR);
  sigaddset(&sigset, TIMER_VAN);
  sigaddset(&sigset, TIMER_OUT);
  pthread_sigmask(SIG_BLOCK, &sigset, NULL);

  Control c;
  c.cars = 0;
  c.vans = 0;
  c.car.interval = 2;
  c.van.interval = 3;
  c.interval = 2;
  pthread_mutex_init(&c.random, NULL);
  pthread_mutex_init(&c.mutex, NULL);

  pthread_create(&c.car.thread, NULL, car_task, &c);
  pthread_create(&c.van.thread, NULL, van_task, &c);
  pthread_create(&c.in, NULL, in_task, &c);
  pthread_create(&c.out, NULL, out_task, &c);

  pthread_join(c.car.thread, NULL);
  pthread_join(c.van.thread, NULL);
  pthread_join(c.in, NULL);
  pthread_join(c.out, NULL);

  pthread_mutex_destroy(&c.random);
  pthread_mutex_destroy(&c.mutex);

  return 0;
}

// ================================

void* car_task(void* arg) {
  Control* c = (Control*) arg;
  timer_t timer;
  sigset_t thread_set;
  sigemptyset(&thread_set);
  sigaddset(&thread_set, TIMER_CAR);
  create_timer(&timer, TIMER_CAR);
  activate_timer(timer, c->car.interval, 0);

  while (true) {
    int info;
    sigwait(&thread_set, &info);

    if (info == TIMER_CAR) {
      kill(getpid(), IN_CAR);
    }
  }

  timer_delete(timer);
}

// ================================

void* van_task(void* arg) {
  Control* c = (Control*) arg;
  timer_t timer;
  sigset_t thread_set;
  sigemptyset(&thread_set);
  sigaddset(&thread_set, TIMER_VAN);
  create_timer(&timer, TIMER_VAN);
  activate_timer(timer, c->van.interval, 0);

  while (true) {
    int info;
    sigwait(&thread_set, &info);

    if (info == TIMER_VAN) {
      kill(getpid(), IN_VAN);
    }
  }

  timer_delete(timer);
}

// ================================

void* in_task(void* arg) {
  Control* c = (Control*) arg;
  timer_t timer;
  sigset_t thread_set;
  sigemptyset(&thread_set);
  sigaddset(&thread_set, TIMER_OUT);
  sigaddset(&thread_set, IN_CAR);
  sigaddset(&thread_set, IN_VAN);
  create_timer(&timer, TIMER_OUT);
  activate_timer(timer, c->van.interval, 0);

  while (true) {
    int info;
    sigwait(&thread_set, &info);

    if (info == TIMER_OUT) {
      long r = generate_random(&c->random);
      (r) ? kill(getpid(), OUT_CAR) : kill(getpid(), OUT_VAN);
    } else if (info == IN_CAR) {
      pthread_mutex_lock(&c->mutex);
      c->cars++;
      printf("car got in (%d cars)\n", c->cars);
      pthread_mutex_unlock(&c->mutex);
    } else if (info == IN_VAN) {
      pthread_mutex_lock(&c->mutex);
      c->vans++;
      printf("van got in (%d vans)\n", c->vans);
      pthread_mutex_unlock(&c->mutex);
    }
  }

  timer_delete(timer);
}

// ================================

void* out_task(void* arg) {
  Control* c = (Control*) arg;
  sigset_t thread_set;
  sigemptyset(&thread_set);
  sigaddset(&thread_set, OUT_CAR);
  sigaddset(&thread_set, OUT_VAN);

  while (true) {
    int info;
    sigwait(&thread_set, &info);
    pthread_mutex_lock(&c->mutex);

    if (info == OUT_CAR && c->cars > 0) {
      c->cars--;
      printf("car got out (%d cars)\n", c->cars);
    } else if (info == OUT_VAN && c->vans > 0) {
      c->vans--;
      printf("van got out (%d vans)\n", c->vans);
    }

    pthread_mutex_unlock(&c->mutex);
  }
}
