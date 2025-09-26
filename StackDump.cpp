#include "stack.h"
#include "my_logger.h"

void StackDump(stk_t *stk, const char *file, const char *func, size_t line) //parametr for data
{
    if (IS_BAD_PTR(stk))
    {
        fprintf(LogFile, "---------------------------------------------------------------------------------------------------------------------------\n\n");
        
        fprintf(LogFile, "StackDump() from %s at %s:%zu: Bad stack at function\n", func, file, line);
        fprintf(LogFile, "Stack <int> [NULL] ERROR! BAD_STK_PTR\n");

        fprintf(LogFile, "\n---------------------------------------------------------------------------------------------------------------------------\n");
        return;
    }

    if (stk->canary_1 != CANARY_1 || stk->canary_2 != CANARY_2)
    {
        fprintf(LogFile, "---------------------------------------------------------------------------------------------------------------------------\n\n");
        
        fprintf(LogFile, "StackDump() from %s at %s:%zu: Bad stack at function\n", func, file, line);

        if (!IS_BAD_PTR((*stk).id.name) && !IS_BAD_PTR((*stk).id.file) && !IS_BAD_PTR((*stk).id.func) && (*stk).id.line >= 0)
            fprintf(LogFile, "Stack <int> \"%s\" [%p] from %s:%zu: ERROR! WRONG_CANARY\n", (*stk).id.name + 1, stk, (*stk).id.file, (*stk).id.line);
        
        else
            fprintf(LogFile, "Stack <int> [%p] ERROR! WRONG_CANARY\n", stk);
        
        fprintf(LogFile, "\n---------------------------------------------------------------------------------------------------------------------------\n");
        return;
    }

    fprintf(LogFile, "---------------------------------------------------------------------------------------------------------------------------\n\n");
    
    fprintf(LogFile, "StackDump() from %s at %s:%zu: Bad stack at function\n", func, file, line);
    
    if (!IS_BAD_PTR((*stk).id.name) && !IS_BAD_PTR((*stk).id.file) && !IS_BAD_PTR((*stk).id.func) && (*stk).id.line > 0)
        fprintf(LogFile, "Stack <int> \"%s\" [%p] from %s:%zu: ERROR! \n", (*stk).id.name + 1, stk, (*stk).id.file, (*stk).id.line);
    
    else
        fprintf(LogFile, "Stack <int> [%p] ERROR! \n", stk);
        
    #define PRINT_ERRCODE_(code)  fprintf(LogFile, "%s", (ERR_CHECK(code)) ? #code " " : "")

    PRINT_ERRCODE_(BAD_DATA_PTR);
    PRINT_ERRCODE_(WRONG_SIZE);
    PRINT_ERRCODE_(WRONG_CAPACITY);
    PRINT_ERRCODE_(DATA_OVERFLOW);
    PRINT_ERRCODE_(ACCESS_EMPTY_DATA);
    PRINT_ERRCODE_(BAD_INCREASED_STK_PTR);
    PRINT_ERRCODE_(WRONG_REALLOC);

    #undef PRINT_ERRCODE_

    fprintf(LogFile, "\n");

    if (ERR_CHECK(BAD_DATA_PTR) == SUCCESS && stk->capacity > 0 && stk->size > 0)
    {
        fprintf(LogFile, "data[%p]\n", stk->data);
        fprintf(LogFile, "{\n");

        for (size_t i = 0; i < (size_t)stk->capacity; ++i)
        {
            fprintf(LogFile, "\t%s[%zu] = %d\n", (i <= (size_t)stk->size) ? "*": "", i, stk->data[i]);
        }

        fprintf(LogFile, "}\n");
    }

    fprintf(LogFile, "\n---------------------------------------------------------------------------------------------------------------------------\n\n");
}