#include "stack.h"
#include "hash.h"

StackErr_t StackPush(stk_t *stk, stk_elem_t value)
{
    if (ERR_DETECT(stk, STK_PUSH))
        return ERROR;

    if (StackRealloc(stk))
        return ERROR;

    if (ERR_DETECT(stk, STK_PUSH))
        return ERROR;

    stk->data[stk->size - 1] = value;
    stk->size++;

    hash_arr[stk->hash_index] = HashFunc(stk);

    return SUCCESS;
}