#include "stack.h"

StackErr_t StackPop(stk_t *stk, stk_elem_t *last_value)
{
    stk->size--;

    if (ERR_DETECT(stk, STK_POP))
        return ERROR;

    *last_value = stk->data[stk->size];
    stk->data[stk->size] = '\0';

    return SUCCESS;
}