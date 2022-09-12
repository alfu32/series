#ifndef _primes_c
#define _primes_c
#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int weird(char i)
{
    char rectangleWidth, rectangleHeight = i;
    rectangleWidth = rectangleHeight;

    while (rectangleWidth > 0)
    {
        rectangleWidth += -1;

        if (prime(rectangleWidth + 1))
        {
            goto theend;
        }
        else
        {
            rectangleWidth++;
            printf("%d,", rectangleWidth);
        }
        rectangleWidth--;
    theend:
        continue;
    }
    printf("\n");
    return 0;
}
int print_all_primes(char start)
{
    int prime_list_len = primes_len(start);
    int *prime_list = (int *)malloc(sizeof(int) * prime_list_len);
    prime_list = primes(prime_list_len, prime_list, start);
    for (char i = 0; i < prime_list_len; i++)
    {
        printf("prime[%d]=%d\n", i, prime_list[i]);
    }
    printf("\n");

    return 0;
}

int prime(int u)
{
    for (int I = 2; I < u; I++)
    {
        if (u % I == 0)
            return 1;
    }
    return 0;
}
int primes_len(int u)
{
    int len = 0;
    for (char i = u; i > 0; i--)
    {
        if (is_prime(i) == 1)
        {
            len++;
        }
    }
    return len;
}
int is_prime(int u)
{
    for (int i = 2; i < ((u >> 1) + 1); i++)
    {
        if ((u % i) == 0)
            return 0;
    }
    return 1;
}
int *primes(int len, int *vector, int n)
{
    int vec_index = 0;
    for (int i = n; i > 0; i--)
    {
        if (is_prime(i) == 1)
        {
            vector[vec_index] = i;
            vec_index++;
        }
    }
    return vector;
}

s_dynamic_list<int> *get_primes_series(int n)
{
    s_dynamic_list<int> *list = pub_dynamic_list_create<int>(100);
    for (int i = n; i > 0; i--)
    {
        if (is_prime(i) == 1)
        {
            pub_dynamic_list_push(list, i);
        }
    }
    return list;
}
#endif