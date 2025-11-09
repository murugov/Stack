#include "stack.h"

#define PATH_TO_LOGFILE "ReportFiles/LogFile.log"

int main()
{
    LogFileOpener(PATH_TO_LOGFILE);

    stk_t<int> stk_1 = {};
    STACK_INIT(&stk_1, 16);

    StackDtor(&stk_1);

    LogFileCloser();
    return 0;
}