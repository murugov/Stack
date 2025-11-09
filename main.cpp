#include "stack.h"

#define PATH_TO_LOGFILE "ReportFiles/LogFile.log"

int main()
{
    LogFileOpener(PATH_TO_LOGFILE);

    stk_t<int> stk_1;
    STACK_INIT(&stk_1, 16);

    StackPush(&stk_1, 1);
    StackPush(&stk_1, 2);
    StackPush(&stk_1, 3);
    stk_1.data[9] = 8;
    StackPush(&stk_1, 4);


    // StackDump(&stk_1, __FILE__, __func__, __LINE__);

    StackDtor(&stk_1);

    LogFileCloser();
    return 0;
}