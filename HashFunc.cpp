#include "hash.h"

hash_t *hash_arr = {};
static size_t hash_arr_cap = 0;
static size_t hash_arr_size = 0;

hash_t HashFunc(stk_t *stk) //по байтам структуру
{
    hash_t new_hash = 0;

    if (IS_BAD_PTR(stk) || IS_BAD_PTR(stk->data))
        return new_hash;

    new_hash = (new_hash << 5) - new_hash + (hash_t)stk;

    new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->canary_1);

    new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->data);
    for (size_t i = 0; i < (size_t)stk->capacity; ++i)
        new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->data[i]);
    
    new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->size);

    new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->capacity);

    new_hash = (new_hash << 5) - new_hash + (hash_t)(stk->canary_2);

    return new_hash;
}

StackErr_t HashArrCtor()
{
    if (hash_arr_cap == 0)
    {    
        hash_arr = (hash_t*)calloc(32, sizeof(hash_t));

        if (IS_BAD_PTR(hash_arr))
            return ERROR;

        hash_arr_cap = 32;
        hash_arr_size = 0;

    }
    
    return SUCCESS;
}

StackErr_t HashAdd(stk_t *stk)
{
    if(HashArrRealloc())
        return ERROR;

    hash_arr[hash_arr_size] = HashFunc(stk);
    stk->hash_index = hash_arr_size;
    hash_arr_size++;

    return SUCCESS;
}

StackErr_t HashArrRealloc()
{
    if (hash_arr_size + 1 >= hash_arr_cap)
    {
        hash_arr_cap = hash_arr_cap << 1;
        hash_t *new_arr = (hash_t*)realloc(hash_arr, hash_arr_cap * sizeof(hash_t));

        if(IS_BAD_PTR(new_arr))
            return ERROR;

        for (size_t i = hash_arr_cap / 2; i < hash_arr_cap; ++i)
            new_arr[i] = 0;

        hash_arr = new_arr;
    }

    return SUCCESS;
}

// void HashArrDtor() // Special function for array of stacks
// {
//     free(hash_arr);
// }