#include "stack.h"

StackErr_t StackCtor(stk_t *stk, cap_t capacity)
{
    stk->size = 0;
    stk->capacity = capacity;

    if (ERR_DETECT(stk, STK_CTOR))
        return ERROR;

    stk->data = (stk_elem_t *)calloc((size_t)capacity, sizeof(stk_elem_t));

    if (ERR_DETECT(stk, STK_CTOR))
        return ERROR;

    return SUCCESS;
}