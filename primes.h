#ifndef _primes_h
#define _primes_h
#include <stdio.h>
#include <stdlib.h>

int prime(int u);
int weird(char i);

int is_prime(int u);
int print_all_primes(char i);
int primes_len(int n);
int *primes(int len, int *vector, int n);

#include "primes.c"
#endif