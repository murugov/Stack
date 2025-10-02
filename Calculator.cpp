#include <math.h>
#include "stack.h"
#include "task.h"
#include "files.h"

TaskErr_t Calculator(FILE *stream)
{
    stk_t stk = {};
    STACK_INIT(&stk, 32);

    if (IS_BAD_PTR(TaskFile))
        return BAD_INPUT_FILE_PTR;

    ssize_t file_size = SizeFile(stream);
    
    if (file_size < 0)
        return WRONG_FILE_INFO;

    char* buffer = (char*)calloc((size_t)file_size + 2, sizeof(char));
    if (IS_BAD_PTR(buffer))
        return BUFFER_FAIL;

    size_t capacity = fread(buffer, sizeof(char), (size_t)file_size, stream);
    buffer[capacity] = '\0';

    size_t count_n = CmdNumber(buffer);

    char **arr_ptr = (char**)calloc(count_n + 1, sizeof(char*));
    
    if (IS_BAD_PTR(arr_ptr))
        return BAD_ARR_PTR;
    
    ArrPtrCtor(buffer, arr_ptr);

    CalcExecutor(&stk, arr_ptr, count_n);

    free(buffer);
    free(arr_ptr);
    StackDtor(&stk);

    return TASK_SUCCESS;
}

TaskErr_t CalcExecutor(stk_t *stk, char **arr_ptr, size_t count_n)
{
    for (size_t i = 0; i < count_n; ++i)
    {
        cmd_t cmd = 0;
        sscanf(arr_ptr[i], "%d ", &cmd);

        CalcFunc(stk, arr_ptr[i], cmd);
    }
 
    return TASK_SUCCESS;
}

TaskErr_t CalcFunc(stk_t *stk, char *ptr, cmd_t cmd)
{
    stk_elem_t number_1 = 0;
    stk_elem_t number_2 = 0;

    switch (cmd)
    {
        case Inv_cmd_PUSH:
            sscanf(ptr, "%d %d ", &cmd, &number_1);

            StackPush(stk, number_1);
            break;

        case Inv_cmd_ADD:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, number_1 + number_2);
            break;

        case Inv_cmd_SUB:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, number_2 - number_1);
            break;

        case Inv_cmd_MUL:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, number_1 * number_2);
            break;

        case Inv_cmd_DIV:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, number_2 / number_1);
            break;

        case Inv_cmd_POW:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, (stk_elem_t)pow(number_2, number_1));
            break;

        case Inv_cmd_MOD:
            StackPop(stk, &number_1);
            StackPop(stk, &number_2);

            StackPush(stk, number_2 % number_1);
            break;

        case Inv_cmd_SQRT:
            StackPop(stk, &number_1);

            StackPush(stk, (stk_elem_t)sqrt(number_1));
            break;

        case Inv_cmd_OUT:
            StackPop(stk, &number_1);

            printf("OUT: %d\n", number_1);
            break;

        case Inv_cmd_HLT:
            break;

        default:
            return UNKNOWN_CMD;
    }

    return TASK_SUCCESS;
}