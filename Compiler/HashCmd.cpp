#include "compile.h"

hash_t HashCmd(char *cmd)
{
    hash_t new_hash = 0;

    if (IS_BAD_PTR(cmd))
        return new_hash;

    while (*cmd != ' ' && *cmd != '\0')
    {
        new_hash = (new_hash << 5) - new_hash + (hash_t)(*cmd);
        cmd++;
    }

    return new_hash;
}