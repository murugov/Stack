#include "stack.h"
#include "hash.h"

StackErr_t StackCtor(stk_t *stk, cap_t capacity)
{   
    stk->size = 2;
    stk->capacity = capacity + 2;

    if (ERR_DETECT(stk, STK_CTOR))
        return ERROR;

    stk->data = (stk_elem_t *)calloc((size_t)capacity + 2, sizeof(stk_elem_t));

    if (ERR_DETECT(stk, STK_CTOR))
        return ERROR;

    stk->data[0] = CANARY_3;
    stk->data[stk->capacity - 1] = CANARY_4;

    if(HashArrCtor())
    {
        stk->error = BAD_HASH_ARR_PTR;
        StackDump(stk, __FILE__, __FUNCTION__, __LINE__);
        
        return ERROR;
    }

    if (HashAdd(stk))
    {
        stk->error = WRONG_HASH;
        StackDump(stk, __FILE__, __FUNCTION__, __LINE__);
        
        return ERROR;
    }

    return SUCCESS;
}