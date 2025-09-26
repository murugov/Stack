#include "stack.h"

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