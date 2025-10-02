#include "stack.h"
#include "hash.h"

StackErr_t ErrDetect(stk_t *stk, StackFunc IncomingFunc, const char *file, const char *func, size_t line)
{
    StackErr_t err_verd = StackVerify(stk, IncomingFunc);

    if (err_verd == ERROR)
    {
        StackDump(stk, file, func, line);
        return ERROR;
    }
    
    return SUCCESS;
}

StackErr_t StackVerify(stk_t *stk, StackFunc IncomingFunc)
{
    if (IS_BAD_PTR(stk))
        return ERROR;

    stk->error = 0;

    if (stk->canary_1 != CANARY_1 || stk->canary_2 != CANARY_2)
    {
        stk->error |= WRONG_CANARY;
        return ERROR;
    }

    if (IncomingFunc != STK_CTOR && IncomingFunc != STK_POP && HashFunc(stk) != hash_arr[stk->hash_index])
    {
        stk->error |= WRONG_HASH;
        return ERROR;
    }

    if (IncomingFunc != STK_CTOR && !IS_BAD_PTR(stk->data) && (stk->data[0] != CANARY_3 || (stk->capacity > 0 && stk->data[stk->capacity - 1] != CANARY_4)))
    {
        stk->error |= WRONG_CANARY;
        return ERROR;
    }

    if (IS_BAD_PTR(stk->data) && IncomingFunc != STK_PUSH && IncomingFunc != STK_CTOR)
        stk->error |= BAD_DATA_PTR;

    if (stk->size < 2 && IncomingFunc != STK_POP)
        stk->error |= WRONG_SIZE;

    if (stk->capacity < 2)
        stk->error |= WRONG_CAPACITY;

    if (stk->size >= stk->capacity)
        stk->error |= DATA_OVERFLOW;

    if (stk->size < 2 && IncomingFunc == STK_POP)
        stk->error |= ACCESS_EMPTY_DATA;

    if (IS_BAD_PTR(stk->data) && IncomingFunc == STK_PUSH)
        stk->error |= BAD_INCREASED_STK_PTR;
    
    if (IS_BAD_PTR(stk->data) && IncomingFunc == STK_REALLOC)
        stk->error |= WRONG_REALLOC;

    if (stk->error != SUCCESS)
        return ERROR;

    return SUCCESS;
}