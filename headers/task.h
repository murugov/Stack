#ifndef TASK_FILE_H
#define TASK_FILE_H

#include <stdio.h>

enum TaskErr_t
{
    TASK_ERROR = 1,
    TASK_SUCCESS = 0,
    BAD_INPUT_FILE_PTR = -1,
    BAD_OUTPUT_FILE_PTR = -2,
    WRONG_FILE_INFO = -3,
    BUFFER_FAIL = -4,
    BAD_ARR_PTR = -5,
    UNKNOWN_CMD = -6
};

enum InvCmdCode
{
    Inv_cmd_PUSH = 1,
    Inv_cmd_ADD = 2,
    Inv_cmd_SUB = 3,
    Inv_cmd_MUL = 4,
    Inv_cmd_DIV = 5,
    Inv_cmd_POW = 6,
    Inv_cmd_MOD = 7,
    Inv_cmd_SQRT = 8,
    Inv_cmd_OUT = 9,
    Inv_cmd_HLT = 10
};

typedef int cmd_t;

TaskErr_t Calculator(FILE *stream);
ssize_t SizeFile(FILE* stream);
size_t CmdNumber(char* buffer);
void ArrPtrCtor(char *buffer, char **arr_ptr);
TaskErr_t CalcExecutor(stk_t *stk, char **arr_ptr, size_t count_n);
TaskErr_t CalcFunc(stk_t *stk, char *ptr, cmd_t cmd);

#endif