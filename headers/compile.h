#ifndef COMPILE_H
#define COMPILE_H

#include <stdio.h>
#include <stdlib.h>

enum AsmErr_t
{
    ERROR = 1,
    SUCCESS = 0,
    BAD_INPUT_FILE_PTR = -1,
    BAD_OUTPUT_FILE_PTR = -2,
    WRONG_FILE_INFO = -3,
    BUFFER_FAIL = -4,
    BAD_ARR_PTR = -5,
    UNKNOWN_CMD = -6
};

enum CmdCode
{
    cmd_PUSH = 2467610,
    cmd_ADD = 64641,
    cmd_SUB = 82464,
    cmd_MUL = 76708,
    cmd_DIV = 67697,
    cmd_POW = 79416,
    cmd_MOD = 76514,
    cmd_SQRT = 2553120,
    cmd_OUT = 78638,
    cmd_HLT = 71632
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

typedef int calc_elem;
typedef size_t hash_t;

struct commands
{
    InvCmdCode cmd;
    const char *body;
};

bool IsBadPtr(void* ptr);
ssize_t SizeFile(FILE* stream);
size_t CmdNumber(char* buffer);
AsmErr_t Compiler();
void ArrPtrCtor(char *buffer, char **arr_ptr);
AsmErr_t assembly(char **arr_ptr, size_t count_n);
hash_t HashCmd(char *buffer);
AsmErr_t HashArrCtor();
void ErrPrint(AsmErr_t verd);

#define IS_BAD_PTR(ptr) IsBadPtr((void*)ptr)

#endif