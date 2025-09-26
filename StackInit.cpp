#include "stack.h"

void StackInit(stk_t *stk, const char *name, const char *file, const char *func, size_t line)
{
    (*stk).id.name = name;
    (*stk).id.file = file;
    (*stk).id.func = func;
    (*stk).id.line = line;
}