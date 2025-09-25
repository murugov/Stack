#include "choice_mode.h"
#include "struct_parametrs.h"

int choice_mode()
{
    int mode = 0;

    printf("\n-----------------------------------------------------------------\n");
    printf(ANSI_COLOR_BLUE "###    Enter 't' for tester mode and 'u' for user mode    ###\n" ANSI_COLOR_RESET);

    while (VERDICT_WARNING)
     {
        printf(ANSI_COLOR_YELLOW "");
        mode = getchar();

        if ((mode == 'u' || mode == 't') && getchar() == '\n')
            break;

        mode = 0;
        printf("" ANSI_COLOR_RESET);
        
        while (getchar() != '\n');

        printf(ANSI_COLOR_RED "Invalid input format" ANSI_COLOR_RESET "\n");
    }

    printf("\n");

    return mode;
}