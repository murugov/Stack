#include "stack.h"

#ifndef STACK_DUMP_HPP
#define STACK_DUMP_HPP


template <typename stackElem_T>
StackErr_t StackDump(stk_t<stackElem_T> *stk, const char *file, const char * func, int line)
{
    ON_DEBUG( if (IS_BAD_PTR(stk)) { LOG(ERROR, ERR_MSG_FORMAT("STK_BAD_STK_PTR"), ERR_MSG_PARAMS); return STK_ERROR; } )

    #define PRINT_ERRCODE_(code) do { if (ERR_CHECK(code) == STK_ERROR) LOG(ERROR, #code); } while(0)

    PRINT_ERRCODE_(STK_WRONG_CANARY);
    PRINT_ERRCODE_(STK_WRONG_HASH);
    PRINT_ERRCODE_(STK_BAD_HASH_ARR_PTR);
    PRINT_ERRCODE_(STK_BAD_DATA_PTR);
    PRINT_ERRCODE_(STK_WRONG_SIZE);
    PRINT_ERRCODE_(STK_WRONG_CAPACITY);
    PRINT_ERRCODE_(STK_WRONG_REALLOC);
    PRINT_ERRCODE_(STK_WRONG_POISON_VAL);
    PRINT_ERRCODE_(STK_DATA_OVERFLOW);
    PRINT_ERRCODE_(STK_ACCESS_EMPTY_DATA);

    #undef PRINT_ERRCODE_

    if (ERR_CHECK(STK_BAD_DATA_PTR) == STK_NO_ERRORS && stk->capacity > 2 && stk->size > 2)
    {
        fprintf(LogFile, "---------------------------------------------------------------------------------------------------------------------------\n");

        char str_value[32] = {0};

        fprintf(LogFile, "DUMP stack \"%s\" [%p] from %s at %s:%d:\n\n", stk->id.name, stk, func, file, line);

        fprintf(LogFile, "STK_POISON = %d\n\n", STK_POISON);

        fprintf(LogFile, "STK_CANARY_1 = %d\n", STK_CANARY_1);
        fprintf(LogFile, "STK_CANARY_2 = %d\n", STK_CANARY_2);  
        fprintf(LogFile, "STK_CANARY_3 = %d\n", STK_CANARY_3);
        fprintf(LogFile, "STK_CANARY_4 = %d\n\n", STK_CANARY_4);

        fprintf(LogFile, "%s {\n", stk->id.name);

        snprintf(str_value, sizeof(str_value), FORMAT_SPECIFIER(stk->canary_1), stk->canary_1);
        fprintf(LogFile, "\tcanary_1 = %s; (STK_CANARY_1)\n", str_value);

        fprintf(LogFile, "\tdata = {\n");

        snprintf(str_value, sizeof(str_value), FORMAT_SPECIFIER(stk->data[0]), stk->data[0]);
        fprintf(LogFile, "\t\t[0] = %s, (STK_CANARY_3)\n", str_value);

        for (ssize_t i = 1; i < stk->capacity - 1; ++i)
        {
            snprintf(str_value, sizeof(str_value), FORMAT_SPECIFIER(stk->data[i]), stk->data[i]);
            fprintf(LogFile, "\t\t[%zd] = %s, %s\n", i, str_value, (i <= stk->size - 2) ? "": "(STK_POISON)");
        }

        snprintf(str_value, sizeof(str_value), FORMAT_SPECIFIER(stk->data[stk->capacity - 1]), stk->data[stk->capacity - 1]);
        fprintf(LogFile, "\t\t[%zd] = %s (STK_CANARY_4)\n", stk->capacity - 1, str_value);
        fprintf(LogFile, "\t\t};\n");

        fprintf(LogFile, "\tsize = %zd;\n", stk->size);
        fprintf(LogFile, "\tcapacity = %zd;\n", stk->capacity);
        fprintf(LogFile, "\thash = %zx;\n", stk->hash);

        snprintf(str_value, sizeof(str_value), FORMAT_SPECIFIER(stk->canary_2), stk->canary_2);
        fprintf(LogFile, "\tcanary_2 = %s; (STK_CANARY_2)\n", str_value);

        fprintf(LogFile, "}\n");

        fprintf(LogFile, "---------------------------------------------------------------------------------------------------------------------------\n");
    }
        
    return STK_SUCCESS;
}

#endif