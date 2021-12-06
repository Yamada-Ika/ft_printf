#!/bin/bash

echo -n 'Enter test case : '
read TEST_CASE

gcc -D ${TEST_CASE} test_main.c ../libftprintf.a && ./a.out
