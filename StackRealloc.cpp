#include "stack.h"

StackErr_t StackRealloc(stk_t *stk)
{
    if (stk->size + 1 >= stk->capacity)
    {
        stk->capacity *= 2;
        stk_elem_t *new_data = (stk_elem_t*)realloc(stk->data, (size_t)stk->capacity * sizeof(stk_elem_t));

        if(new_data == NULL) //ErrCodes
            return ERROR;

        for (size_t i = (size_t)(stk->capacity / 2); i < (size_t)stk->capacity; ++i)
            new_data[i] = '\0';

        stk->data = new_data;
    }

    return SUCCESS;
}