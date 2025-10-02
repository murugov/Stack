#include "compile.h"

FILE *SourceFile = fopen("CompileFiles/source.asm", "r");
FILE *TaskFile = fopen("CompileFiles/task.asm", "w");


int main()
{
    AsmErr_t compile_verd = Compiler();

    if(compile_verd)
    {
        ErrPrint(compile_verd);
    }

    fclose(SourceFile);
    fclose(TaskFile);

    return 0;
}