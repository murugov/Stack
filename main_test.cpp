#include "stack.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "w");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "r");

int main_test()
{
    Calc(TaskFile);

    fclose(LogFile);
    fclose(TaskFile);

    return 0;
}

    // stk_t stk1 = {};
    // STACK_INIT(&stk1, 5);

    // memset(&stk1, -1, sizeof (stk1));

    // StackPush(&stk1, 10);
    // StackPush(&stk1, 20);
    // StackPush(&stk1, 30);

    // stk_elem_t last_value = 0;
    // StackPop(&stk1, &last_value);
    
    // StackDtor(&stk1);