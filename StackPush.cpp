#include "stack.h"

StackErr_t StackPush(stk_t *stk, stk_elem_t value)
{
    if (ERR_DETECT(stk, STK_PUSH))
        return ERROR;

    if (StackRealloc(stk))
        return ERROR;

    if (ERR_DETECT(stk, STK_PUSH))
        return ERROR;

    stk->data[stk->size++] = value;

    return SUCCESS;
}