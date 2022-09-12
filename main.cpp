#include <stdio.h>
#include <stdlib.h>
#include "collatz.h"
#include "primes.h"
#include "dynamic-list.h"

void print_vector(int len, int *vec, const char *prefix);
int coco(int v,int i,int*arr){
        printf("collatz[%d]=%d\n",i,v);
        return 0;
}
int main(int argc, char *argv[])
{
    int start;
    if (argc < 2)
    {
        printf("starting number : ");
        scanf("%d", &start);
    }
    else
    {
        start = atoi(argv[1]);
        printf("starting number : %d{%s}\n", start, argv[1]);
    }
    /////////// weird(start);
    /////////// printf("\n -------------- ");
    /////////// printf("\n -------------- ");
    /////////// printf("\n -------------- \n");
    /////////// 
    /////////// int collatz_steps = collatz_len(start);
    /////////// printf("colatz steps [%d] = %d \n", start, collatz_steps);
    /////////// int *c = (int *)malloc(sizeof(int) * (collatz_steps+1));
    /////////// c = collatz(collatz_steps, c, start);
    /////////// print_vector(collatz_steps, c, "collatz");
    /////////// printf("\n");
    /////////// free(c);
    /////////// printf("\n");
    /////////// 
    /////////// int primes_steps = primes_len(start);
    /////////// printf("primes length [%d] = %d \n", start, primes_steps);
    /////////// int *p = (int *)malloc(sizeof(int) * (primes_steps+1));
    /////////// p = primes(primes_steps, p, start);
    /////////// printf("\n");
    /////////// print_vector(primes_steps, p, "primes");
    /////////// printf("\n");
    /////////// free(p);

    printf("start\n");
    printf("collatz init\n");
    s_dynamic_list<int> *collatz_series = get_collatz_series(start);
    printf("prime init\n");
    s_dynamic_list<int> *primes_series = get_primes_series(start);
    
    printf("collatz reverse\n");
    pub_dynamic_list_reverse(collatz_series);
    printf("prime reverse\n");
    pub_dynamic_list_reverse(primes_series);
    
    printf("collatz print\n");
    pub_dynamic_list_foreach<int>(collatz_series,[](int v,int i,int* a) -> int{
        printf("collatz[%d]=%d\n",i,v);
        return 0;
    });
    printf("prime print\n");
    pub_dynamic_list_foreach<int>(primes_series,[](int v,int i,int* a) -> int{
        printf("primes[%d]=%d\n",i,v);
    });
    
    printf("prime filter out odd values\n");
    s_dynamic_list<int> *filtered_primes = pub_dynamic_list_filter<int>(primes_series,[](int v,int i,int* a) -> int{
        if( v%2 == 0) {
            return 1;
        }else {
            return 0;
        }
    });
    printf("filtered_primes print\n");
    pub_dynamic_list_foreach<int>(filtered_primes,[](int v,int i,int* a) -> int{
        printf("filtered_primes[%d]=%d\n",i,v);
    });

    typedef struct complex{int x;int y;} complex;
    
    printf("transformed primes\n");
    s_dynamic_list<complex> *masked_primes = pub_dynamic_list_transform<int,complex>(primes_series,[](int v,int i,int* a) -> complex {
        return {x:v,y:i};
    });
    printf("transformed primes print\n");
    pub_dynamic_list_foreach<complex>(masked_primes,[](complex v,int i,complex* a) -> complex{
        printf("masked_primes[%d]= %d + %di\n",i,v.x,v.y);
    });
    pub_dynamic_list_destroy(collatz_series);
    pub_dynamic_list_destroy(primes_series);
    pub_dynamic_list_destroy(filtered_primes);
    return 0;
}


void print_vector(int len, int *vec, const char *prefix)
{
    for (int i = 0; i <= len; i++)
    {
        printf("%s[%d]=%d\n", prefix, i, vec[i]);
    }
    printf("\n");
}
