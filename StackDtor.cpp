#include "stack.h"
#include "hash.h"

StackErr_t StackDtor(stk_t *stk)
{
    if (ERR_DETECT(stk, STK_DTOR))
        return ERROR;

    free(stk->data);
    free(&(hash_arr[stk->hash_index]));

    return SUCCESS;
}