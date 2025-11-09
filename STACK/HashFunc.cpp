#include "hash.h"


stk_hash_t *hash_arr = {};

StackErr_t HashArrCtor()
{
    if (hash_arr_cap == 0)
    {    
        hash_arr = (stk_hash_t*)calloc(MIN_NUM_STK, sizeof(stk_hash_t));
        if (IS_BAD_PTR(hash_arr)) return STK_ERROR;

        hash_arr_cap  = MIN_NUM_STK;
        hash_arr_size = 0;
        LOG(INFO, "stk_hash_arr created");
    }
    
    return STK_SUCCESS;
}


StackErr_t HashArrRealloc()
{
    ON_DEBUG( if (IS_BAD_PTR(hash_arr)) return STK_ERROR; )

    size_t new_hash_arr_cap = hash_arr_cap << 1;
    stk_hash_t *new_arr = (stk_hash_t*)realloc(hash_arr, new_hash_arr_cap * sizeof(stk_hash_t));
    if(IS_BAD_PTR(new_arr)) return STK_ERROR;

    for (size_t i = hash_arr_cap; i < new_hash_arr_cap; ++i)
        new_arr[i] = 0;

    hash_arr     = new_arr;
    hash_arr_cap = new_hash_arr_cap;

    LOG(INFO, "stk_hash_arr reallocated");

    return STK_SUCCESS;
}


StackErr_t HashArrDtor()
{
    ON_DEBUG(if(IS_BAD_PTR(stk_hash_arr)) return STK_ERROR;)

    free(stk_hash_arr);

    LOG(INFO, "stk_hash_arr destroed");
    return STK_SUCCESS;
}