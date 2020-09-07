#!/usr/bin/env bash
gcc -Wall -Wextra -Werror -o "$1".bin "$1".c -lpthread -lrt
