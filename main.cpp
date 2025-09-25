#include "unit_test.h"
#include "stdout.h"
#include "square_solver.h"
#include "choice_mode.h"

int main(void)
{
    int mode = choice_mode();

    if (mode == 'u')
    {
        printf(ANSI_COLOR_BLUE "###    This is a quadratic equation calculator              ###\n");
        printf("###    Enter a, b, c separated by space or by enter         ###" ANSI_COLOR_RESET "\n");

        struct parametrs user = {NAN, NAN, NAN, NAN, NAN};
        
        enter(&user);

        int res = quadro_equation(&user);

        output(res, &user);
    }
    else
        test();

    return 0;
}