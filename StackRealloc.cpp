#include "stack.h"
#include "hash.h"

StackErr_t StackRealloc(stk_t *stk)
{
    if (ERR_DETECT(stk, STK_CTOR))
        return ERROR;

    if (stk->size + 1 >= stk->capacity)
    {
        stk->capacity = stk->capacity << 1;
        stk_elem_t *new_data = (stk_elem_t*)realloc(stk->data, (size_t)stk->capacity * sizeof(stk_elem_t));

        if(IS_BAD_PTR(new_data))
        {
            stk->error = WRONG_REALLOC;
            StackDump(stk, __FILE__, __FUNCTION__, __LINE__);

            return ERROR;
        }

        for (size_t i = (size_t)(stk->capacity / 2) - 1; i < (size_t)stk->capacity - 1; ++i)
            new_data[i] = '\0';
        
        new_data[(size_t)stk->capacity - 1] = CANARY_4;

        stk->data = new_data;

        hash_arr[stk->hash_index] = HashFunc(stk);
    }

    return SUCCESS;
}