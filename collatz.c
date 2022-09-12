// 
// struct LinkedIntList {
// LinkedIntList* prev;
// int value;
// LinkedIntList* next
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
