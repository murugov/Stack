#include "stack.h"
#include "task.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "wb");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "rb");

int main()
{
    TaskErr_t calc_verd = Calculator(TaskFile);

    CalcErrPrint(calc_verd);

    fclose(LogFile);
    fclose(TaskFile);

    return 0;
}