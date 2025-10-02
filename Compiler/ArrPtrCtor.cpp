#include <stdio.h>
#include <string.h>
#include "compile.h"

void ArrPtrCtor(char *buffer, char **arr_ptr) // можно написать доп проверку
{
    size_t count_n = 0;
    arr_ptr[count_n++] = buffer; 

    char* str = buffer;
    char* flag_second_n = buffer - 1;

    while ((str = strchr(str, '\n')) != NULL)
    {
        if (flag_second_n + 1 == str)
            flag_second_n++;

        else
        {
            *str = '\0';
            arr_ptr[count_n++] = str + 1;
            flag_second_n = str;
        }

        str++;
    }
}