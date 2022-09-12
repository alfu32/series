#ifndef _dynamic_list_h
#define _dynamic_list_h
#include <stdio.h>
#include <stdlib.h>

template<typename T>
struct s_dynamic_list
{
    T *list;
    int cap;
    int last;
};
template<typename T>
s_dynamic_list<T> *pub_dynamic_list_create(int initial_capacity);

template<typename T>
int pub_dynamic_list_destroy(s_dynamic_list<T> *self);

template<typename T>
int pub_dynamic_list_length(s_dynamic_list<T> *self);
template<typename T>
s_dynamic_list<T> *pub_dynamic_list_push(s_dynamic_list<T> *self, T n);

template<typename T>
int pub_dynamic_list_pop(s_dynamic_list<T> *self);
template<typename T>
s_dynamic_list<T> *pub_dynamic_list_reverse(s_dynamic_list<T> *self);
template<typename T>
s_dynamic_list<T> *pub_dynamic_list_foreach(s_dynamic_list<T> *self, T (*foreach)(T value, int index, T *array) );
template<typename T>
s_dynamic_list<T> *pub_dynamic_list_filter(s_dynamic_list<T> *self,  T (*predicate)(T value, int index, T *array) );
template<typename T,typename R>
s_dynamic_list<R> *pub_dynamic_list_transform(s_dynamic_list<T> *self,  R (*mapper)(T value, int index, T *array) );
template<typename T,typename R>
R* pub_dynamic_list_reduce(s_dynamic_list<T> *self,  R* (*reducer)(R accumulator,T value, int index, T *array), R* initial_value );

#include "dynamic-list.c"
#endif