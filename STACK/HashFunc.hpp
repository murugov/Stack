#include "hash.h"

#ifndef HASH_FUNC_HPP
#define HASH_FUNC_HPP


template <typename stackElem_T>
stk_hash_t HashFunc(stk_t<stackElem_T> *stk)
{
    ON_DEBUG( if (IS_BAD_PTR(stk) || IS_BAD_PTR(stk->data)) return 0; )
    
    stk_hash_t new_hash = 0;

    for (size_t i = 0; i < (size_t)stk->capacity; ++i)
        new_hash = (new_hash << 5) - new_hash + (stk_hash_t)(stk->data[i]);

    new_hash = (new_hash << 5) - new_hash + (stk_hash_t)(stk->size);
    new_hash = (new_hash << 5) - new_hash + (stk_hash_t)(stk->capacity);

    LOG(INFO, "Hash updated");
    return new_hash;
}

template <typename stackElem_T>
StackErr_t HashAdd(stk_t<stackElem_T> *stk)
{
    if (hash_arr_size + 1 >= hash_arr_cap) { if(HashArrRealloc()) return STK_ERROR; }

    stk_hash_arr[hash_arr_size] = HashFunc(stk);
    stk->hash_index         = hash_arr_size++;
    
    LOG(INFO, "Stack \"%s\" is added to the stk_hash_arr", stk->id.name);
    return STK_SUCCESS;
}

#endif