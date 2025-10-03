#include "stack.h"
#include "task.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "w");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "r");

int main()
{
    TaskErr_t calc_verd = Calculator(TaskFile);

    CalcErrPrint(calc_verd);

    fclose(LogFile);
    fclose(TaskFile);

    return 0;
}