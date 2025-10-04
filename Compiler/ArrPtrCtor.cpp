#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "compile.h"

AsmErr_t ArrPtrCtor(char *buffer, char **arr_ptr)
{
    if (IS_BAD_PTR(buffer))
        return BAD_BUFFER_PTR;
    
    size_t count = 0;
    char* line_start = buffer;
    char* next_n = buffer;
    
    while ((next_n = strchr(line_start, '\n')) != NULL)
    {
        int has_content = 0;

        for (char* ptr = line_start; ptr < next_n; ++ptr)
        {
            if (!isspace((unsigned char)*ptr))
            {
                has_content = 1;
                arr_ptr[count] = ptr;
                break;
            }
        }
        
        if (has_content)
            count++;
        
        line_start = next_n + 1;

        *next_n = '\0';
    }
    
    if (*line_start != '\0')
    {
        for (char* ptr = line_start; *ptr != '\0'; ++ptr)
        {
            if (!isspace((unsigned char)*ptr)) 
            {
                arr_ptr[count++] = ptr;
                break;
            }
        }
    }

    return SUCCESS;
}