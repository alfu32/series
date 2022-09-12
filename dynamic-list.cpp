
#ifndef _dynamic_list_c
#define _dynamic_list_c
#include <stdio.h>
#include <stdlib.h>
#include "dynamic-list.h"

template<typename T>
s_dynamic_list<T> *pub_dynamic_list_create(int initial_capacity)
{
    s_dynamic_list<T> *l = (s_dynamic_list<T> *)malloc(sizeof(s_dynamic_list<T>));

    l->list = (T*) malloc(sizeof(T) * initial_capacity);
    l->cap = initial_capacity;
    l->last = 0;
    return l;
}

template<typename T>
int pub_dynamic_list_destroy(s_dynamic_list<T> *self)
{
    free(self->list);
    free(self);
}

template<typename T>
int pub_dynamic_list_length(s_dynamic_list<T> *self)
{
    return self->last + 1;
}

template<typename T>
s_dynamic_list<T> *pub_dynamic_list_push(s_dynamic_list<T> *self, T n)
{
    if (self->last == self->cap)
    {
        printf("reallocating %d -> %d \n", self->cap, self->cap << 1);
        self->cap = self->cap << 1;
        T *newlist = (T*)realloc(self->list, sizeof(T) * (self->cap));
        if (!newlist)
        {
            printf("couldn't reallocate %lu bytes", sizeof(T) * (self->cap));
        }
        else
        {
            self->list = newlist;
        }
    }
    self->last++;
    self->list[self->last - 1] = n;
}

template<typename T>
int pub_dynamic_list_pop(s_dynamic_list<T> *self)
{
    T last = self->list[self->last + 1];
    self->last--;
    self->list[self->last + 1] = 0;
    return last;
}

template<typename T>
s_dynamic_list<T> *pub_dynamic_list_reverse(s_dynamic_list<T> *self)
{
    int last = (self->last-1);
    int half = (last)>>1;
    for(int i = 0; i<=half; i++) {
        printf("%d\n",i);
        T s=self->list[i];
        self->list[i]=self->list[last-i];
        self->list[last-i]=s;
    }
    return self;
}

template<typename T>
s_dynamic_list<T> *pub_dynamic_list_foreach(s_dynamic_list<T> *self,  T (*foreach)(T value, int index, T *array) )
{
    for (int i = 0; i < self->last; i++)
    {
        foreach (self->list[i], i, self->list);
    }
}

template<typename T>
s_dynamic_list<T> *pub_dynamic_list_filter(s_dynamic_list<T> *self,  T (*predicate)(T value, int index, T *array) ) {
    s_dynamic_list<T> *result = pub_dynamic_list_create<T>(self->last);
    int crt = 0;
    for (int i = 0; i < self->last; i++)
    {
        if(predicate(self->list[i],i,self->list) != 0){
            result->list[crt] = self->list[i];
            crt+=1;
        }
    }
    result->last = crt;
    return result;
}

template<typename T,typename R>
s_dynamic_list<R> *pub_dynamic_list_transform(s_dynamic_list<T> *self,  R (*mapper)(T value, int index, T *array) ){
    s_dynamic_list<R> *result = pub_dynamic_list_create<R>(self->last);
    for (int i = 0; i < self->last; i++)
    {
            pub_dynamic_list_push(result,mapper(self->list[i],i,self->list));
    }
    return result;
}
template<typename T,typename R>
R* pub_dynamic_list_reduce(s_dynamic_list<T> *self,  R* (*reducer)(R accumulator,T value, int index, T *array), R* initial_value ){
    for (int i = 0; i < self->last; i++)
    {
            initial_value = reducer(initial_value,self->list[i],i,self->list);
    }
    return initial_value;
}
#endif