#include "compile.h"

FILE *SourceFile = fopen("Compiler/CompileFiles/source.asm", "rb");
FILE *TaskFile = fopen("Compiler/CompileFiles/task.asm", "wb");

int main()
{
    AsmErr_t compile_verd = Compiler();

    ErrPrint(compile_verd);

    fclose(SourceFile);
    fclose(TaskFile);

    return 0;
}