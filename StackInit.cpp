#include "stack.h"

StackErr_t StackInit(stk_t *stk, const char *name, const char *file, const char *func, size_t line)
{
    if (IS_BAD_PTR(stk))
    {
        StackDump(stk, __FILE__, __FUNCTION__, __LINE__);

        return ERROR;
    }
    
    (*stk).id.name = name;
    (*stk).id.file = file;
    (*stk).id.func = func;
    (*stk).id.line = line;

    return SUCCESS;
}