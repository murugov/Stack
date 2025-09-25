#include "stdout.h"
#include "my_assert.h"
#include "square_solver.h"

void enter(struct parametrs* ptr_structure)
{
    //assert(ptr_structure != NULL)
    MY_ASSERT(ptr_structure != NULL);

    printf(ANSI_COLOR_YELLOW "");
    int checker = scanf("%lg %lg %lg", &ptr_structure->a, &ptr_structure->b, &ptr_structure->c);
    printf("" ANSI_COLOR_RESET);

    while (checker != 3 || getchar() != '\n')
    {
        printf(ANSI_COLOR_YELLOW "");
        while (getchar() != '\n');
        printf("" ANSI_COLOR_RESET);

        printf(ANSI_COLOR_RED "Invalid input format\n" ANSI_COLOR_RESET);

        printf(ANSI_COLOR_YELLOW "");
        checker = scanf("%lg %lg %lg", &ptr_structure->a, &ptr_structure->b, &ptr_structure->c);
        printf("" ANSI_COLOR_RESET);
    }

    printf("\n" ANSI_COLOR_RESET);

    double D = discriminat(ptr_structure);
    
    printf(ANSI_COLOR_MAGENTA "Solution:\n");
    if (D == 0)
        printf("D = b^2 - 4*a*c = %g^2 - 4*%g*%g = %g" ANSI_COLOR_RESET "\n\n",
            ptr_structure->b, ptr_structure->a, ptr_structure->c, D);
    else
        printf("D = b^2 - 4*a*c = %g^2 - 4*%g*%g = %g %c 0" ANSI_COLOR_RESET "\n\n",
            ptr_structure->b, ptr_structure->a, ptr_structure->c, D, (D > 0) ? '>': '<');
}

void output(int res, struct parametrs* ptr_structure)
{
    //assert(ptr_structure != NULL);
    MY_ASSERT(ptr_structure != NULL);

    switch (res)
    {
        case NO_ROOTS:
            printf(ANSI_COLOR_MAGENTA "No roots\n" ANSI_COLOR_RESET);
            printf("-----------------------------------------------------------------\n\n");
            break;
        case ONE_ROOT:
            printf(ANSI_COLOR_MAGENTA "One root:\n");
            printf("x = %lg" ANSI_COLOR_RESET "\n", ptr_structure->x1);
            printf("-----------------------------------------------------------------\n\n");
            break;
        case TWO_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Two roots:\n");
            printf("x1 = %lg\n", ptr_structure->x1);
            printf("x2 = %lg" ANSI_COLOR_RESET "\n", ptr_structure->x2);
            printf("-----------------------------------------------------------------\n\n");
            break;
        case IMAGINARY_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Only imaginary roots\n" ANSI_COLOR_RESET);
            printf("-----------------------------------------------------------------\n\n");
            break;
        case INFINITY_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Infinite number of roots\n" ANSI_COLOR_RESET);
            printf("-----------------------------------------------------------------\n\n");
            break;
        default:
            break;
    }
}