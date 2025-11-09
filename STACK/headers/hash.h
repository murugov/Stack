#include "stack.h"

#ifndef HASH_H
#define HASH_H

typedef size_t stk_hash_t;

extern stk_hash_t *stk_hash_arr;

static size_t hash_arr_cap  = 0;
static size_t hash_arr_size = 0;

template <typename stackElem_T>
stk_hash_t HashFunc(stk_t<stackElem_T> *stk);

StackErr_t HashArrCtor();
StackErr_t HashArrDtor();

template <typename stackElem_T>
StackErr_t HashAdd(stk_t<stackElem_T> *stk);

StackErr_t HashArrRealloc();


#include "../HashFunc.hpp"

#endif