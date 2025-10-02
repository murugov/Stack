#include "stack.h"
#include "hash.h"

StackErr_t StackPop(stk_t *stk, stk_elem_t *last_value)
{
    stk->size--;
    
    if (ERR_DETECT(stk, STK_POP))
        return ERROR;

    *last_value = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = '\0';

    hash_arr[stk->hash_index] = HashFunc(stk);

    return SUCCESS;
}