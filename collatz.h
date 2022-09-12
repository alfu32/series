#ifndef _collatz_h
#define _collatz_h
#include <stdio.h>
#include <stdlib.h>
#include "dynamic-list.h"

int collatz_next(int n);
int collatz_len(int n);
int *collatz(int length, int *vec, int n);
s_dynamic_list<int> *get_collatz_series(int n);

#include "collatz.c"
#endif