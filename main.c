#include <stdio.h>
#include <stdlib.h>

int prime(int u);
int weird(char i);
int allPrimes(char i);
int collatz_next(int n);
int collatz_len(int n);
int* collatz(int length,int* vec,int n);

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



// struct LinkedIntList {
//     LinkedIntList* prev;
//     int value;
//     LinkedIntList* next
// }

// void *LINKED_INT_LIST_NULL = malloc(sizeof(LinkedIntList),1);
// int collatz_next(int n);
int collatz_len(int n){
    // int list =(LinkedIntList*) malloc(sizeof(LinkedIntList),1);
    // list* = LinkedIntList{LINKED_INT_LIST_NULL,0,LINKED_INT_LIST_NULL};
    int ix = 0;
    // count mem size
    int steps = 1;
    int current = n;
    while (current > 1) {
        steps+=1;
        current = collatz_next(current);
    }
    printf("\ncollatz(%d) converges in %d steps\n",n,steps);
    
    return steps-1;
}
int collatz_next(int n){
    printf("%d,",n);
    if ( (n & 1) == 0 ) return n>>1;
    else return 3*n +1;
}
int* collatz(int length,int* vec,int n){
    int c=n;
    while (length>=0){
        vec[length]=c;
        c=collatz_next(c);
        length--;
    }
    return vec;
}