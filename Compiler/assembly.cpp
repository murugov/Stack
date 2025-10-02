#include "compile.h"
#include "GlobalFiles.h"

AsmErr_t TaskWriter(commands *cmds, const char *ptr, hash_t func)
{
    switch (func)
    {
        case cmd_PUSH:
            cmds->cmd = Inv_cmd_PUSH;
            cmds->body = &ptr[4];
            break;

        case cmd_ADD:
            cmds->cmd = Inv_cmd_ADD;
            cmds->body = "\0";
            break;

        case cmd_SUB:
            cmds->cmd = Inv_cmd_SUB;
            cmds->body = "\0";
            break;

        case cmd_MUL:
            cmds->cmd = Inv_cmd_MUL;
            cmds->body = "\0";
            break;

        case cmd_DIV:
            cmds->cmd = Inv_cmd_DIV;
            cmds->body = "\0";
            break;

        case cmd_POW:
            cmds->cmd = Inv_cmd_POW;
            cmds->body = "\0";
            break;

        case cmd_MOD:
            cmds->cmd = Inv_cmd_MOD;
            cmds->body = "\0";
            break;

        case cmd_SQRT:
            cmds->cmd = Inv_cmd_SQRT;
            cmds->body = "\0";
            break;

        case cmd_OUT:
            cmds->cmd = Inv_cmd_OUT;
            cmds->body = "\0";
            break;

        case cmd_HLT:
            cmds->cmd = Inv_cmd_HLT;
            cmds->body = "\0";
            break;

        default:
            return UNKNOWN_CMD;
    }

    return SUCCESS;
}

AsmErr_t assembly(char **arr_ptr, size_t count_n)
{
    commands *cmds = (commands*)calloc(count_n + 1, sizeof(commands));

    for (size_t i = 0; i < count_n; ++i)
    {
        hash_t func = HashCmd(arr_ptr[i]);
        if (TaskWriter(&cmds[i], arr_ptr[i], func))
            return ERROR;
    }

    for (size_t i = 0; i < count_n; ++i)
        fprintf(TaskFile, "%d%s\n", cmds[i].cmd, cmds[i].body);

    
    free(cmds);
        
    return SUCCESS;
}