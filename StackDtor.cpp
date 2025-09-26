#include "stack.h"

StackErr_t StackDtor(stk_t *stk)
{
    if (ERR_DETECT(stk, STK_DTOR))
        return ERROR;

    free(stk->data);

    return SUCCESS;
}