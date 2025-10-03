#include "stack.h"
#include "task.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "w");

int main()
{
    TaskErr_t calc_verd = Calculator(stdin);

    CalcErrPrint(calc_verd);

    fclose(LogFile);

    return 0;
}