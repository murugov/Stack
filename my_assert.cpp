#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "my_assert.h"

void my_assert(bool (condition), const char* name_file, int line_of_file)
{
    if (!condition)
    {
        printf(ANSI_COLOR_RED"Assert failled: file: %s, line: %d\n" ANSI_COLOR_RESET, name_file, line_of_file);
        exit(1);
    }
}