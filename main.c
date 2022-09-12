#include <stdio.h>
#include <stdlib.h>
#include "collatz.h"

int prime(int u);
int weird(char i);
int allPrimes(char i);

int main(int argc,char* argv[]){
    int start;
    if(argc < 2) {
        printf("starting number : ");
        scanf("%d", &start);
    } else {
        start = atoi(argv[1]);
        printf("starting number : %d{%s}\n",start,argv[1]);
    }
    weird(start);
    allPrimes(start);
    int collatz_steps=collatz_len(start);
    printf("colatz steps [%d] = %d \n",start,collatz_steps);
    int*c=(int*)malloc(sizeof(int)*collatz_steps);
    c=collatz(collatz_steps,c,start);
    printf("\n");
    for(int i=0;i<=collatz_steps;i++){
        printf("collatz[%d]=%d\n",i,c[i]);
    }
    printf("\n");
    return 0;
}

int weird(char i){
    char rectangleWidth,rectangleHeight = i;
    rectangleWidth = rectangleHeight;

    while (rectangleWidth > 0) {
        rectangleWidth += -1;

        if(prime(rectangleWidth+1)){
            goto theend;
        } else {
            rectangleWidth++;
            printf("%d,",rectangleWidth);
        }
        rectangleWidth--;
        theend:
            continue;
    }
    printf("\n");
    return 0;

}
int allPrimes(char start){
    for(char i=start;i>0;i--){
        if(prime(i) == 0){
            printf("%d,",i);
        }
    }
    printf("\n");
    
    return 0;
}

int prime(int u) {
    for(int I=2; I<u; I++){
        if(u%I == 0) return 1;
    }
    return 0;
}

