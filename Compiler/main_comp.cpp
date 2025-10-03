#include "compile.h"

FILE *SourceFile = fopen("Compiler/CompileFiles/source.asm", "r");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "w");


int main()
{
    AsmErr_t compile_verd = Compiler();

    ErrPrint(compile_verd);

    fclose(SourceFile);
    fclose(TaskFile);

    return 0;
}