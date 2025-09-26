#include "stack.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "w");

int main()
{
    stk_t stk1 = {};
    STACK_INIT(&stk1, 5);

    //memset(&stk1, -1, sizeof (stk1));
    
    // printf("> stk1[%p]\n", (void*)(stk1.id.name));
    // printf("> IsBadPtr(stk1) = %d\n", (int)IsBadPtr((void*)(stk1.id.name)));

    StackPush(&stk1, 10);
    StackPush(&stk1, 20);
    StackPush(&stk1, 30);

    stk_elem_t last_value = 0;
    StackPop(&stk1, &last_value);
    
    StackDtor(&stk1);

    fclose(LogFile);

    return 0;
}