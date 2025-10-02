#include <stdio.h>
#include "compile.h"
#include "GlobalFiles.h"

AsmErr_t Compiler() // добавить адресс буффера
{
    if (IS_BAD_PTR(SourceFile))
        return BAD_INPUT_FILE_PTR;

    if (IS_BAD_PTR(TaskFile))
        return BAD_OUTPUT_FILE_PTR;

    ssize_t file_size = SizeFile(SourceFile);
    
    if (file_size < 0)
        return WRONG_FILE_INFO;

    char* buffer = (char*)calloc((size_t)file_size + 2, sizeof(char));
    if (IS_BAD_PTR(buffer))
        return BUFFER_FAIL;

    size_t capacity = fread(buffer, sizeof(char), (size_t)file_size, SourceFile);
    buffer[capacity] = '\0';

    size_t count_n = CmdNumber(buffer);

    char **arr_ptr = (char**)calloc(count_n + 1, sizeof(char*));
    
    if (IS_BAD_PTR(arr_ptr))
        return BAD_ARR_PTR;
    
    ArrPtrCtor(buffer, arr_ptr);
    
    if (assembly(arr_ptr, count_n + 1))
        return UNKNOWN_CMD;

    free(buffer);
    free(arr_ptr);

    return SUCCESS;
}









    // char *cmd_PUSH = "PUSH";
    // char *cmd_ADD = "ADD";
    // char *cmad_SUB = "SUB";
    // char *cmd_MUL = "MUL";
    // char *cmd_DIV = "DIV";
    // char *cmd_POW = "POW";
    // char *cmd_MOD = "MOD";
    // char *cmd_SQRT = "SQRT";
    // char *cmd_OUT = "OUT";
    // char *cmd_HLT = "HLT";

    // printf("%zu\n", HashCmd(cmd_PUSH));
    // printf("%zu\n", HashCmd(cmd_ADD));
    // printf("%zu\n", HashCmd(cmad_SUB));
    // printf("%zu\n", HashCmd(cmd_MUL));
    // printf("%zu\n", HashCmd(cmd_DIV));
    // printf("%zu\n", HashCmd(cmd_POW));
    // printf("%zu\n", HashCmd(cmd_MOD));
    // printf("%zu\n", HashCmd(cmd_SQRT));
    // printf("%zu\n", HashCmd(cmd_OUT));
    // printf("%zu\n", HashCmd(cmd_HLT));