#include "stack.h"
#include "task.h"

FILE *LogFile = fopen("ReportFiles/LogFile.log", "w");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "r");

int main()
{
    Calculator(TaskFile);

    fclose(LogFile);
    fclose(TaskFile);

    return 0;
}