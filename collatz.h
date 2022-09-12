#ifndef _collatz_h
#define _collatz_h
    #include <stdio.h>
    #include <stdlib.h>
#endif

int collatz_next(int n);
int collatz_len(int n);
int* collatz(int length,int* vec,int n);

#include "collatz.c"