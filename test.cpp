#include "unit_test.h"
#include "is_zero.h"


void number_of_test_with_error(struct parametrs* ptr_test, int res_test)
{
    int presence_of_error = comparison(ptr_test, res_test);
    
    switch (presence_of_error)
    {
    case VERDICT_OK:
        printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
        break;
    
    case VERDICT_WARNING:
        warning_output(ptr_test, res_test);
        break;
    default:
        break;
    }
}

int comparison(struct parametrs* ptr_test, int res_test)
{
    if (is_zero(res_test - ptr_test->result))
    {
        if (isnan(ptr_test->x1) && isnan(ptr_test->ans_x1))
        {
            if (isnan(ptr_test->x2) && isnan(ptr_test->ans_x2))
                return VERDICT_OK;
            else
            {
                if (!isnan(ptr_test->x2) && !isnan(ptr_test->ans_x2))
                {
                    if (is_zero(ptr_test->x2 - ptr_test->ans_x2))
                        return VERDICT_OK;

                    return VERDICT_WARNING;
                }

                return VERDICT_WARNING;
            }
        }
        else
        {
            if (!isnan(ptr_test->x1) && !isnan(ptr_test->ans_x1))
            {
                if (is_zero(ptr_test->x1 - ptr_test->ans_x1))
                {
                    if (isnan(ptr_test->x2) && isnan(ptr_test->ans_x2))
                        return VERDICT_OK;
                    else
                    {
                        if (!isnan(ptr_test->x2) && !isnan(ptr_test->ans_x2))
                        {
                            if (is_zero(ptr_test->x2 - ptr_test->ans_x2))
                                return VERDICT_OK;
                            
                            return VERDICT_WARNING;
                        }

                        return VERDICT_WARNING;
                    }
                }
                
                return VERDICT_WARNING;
            }

            return VERDICT_WARNING;
        }
    }
    else
        return VERDICT_WARNING;
}

void warning_output(struct parametrs* ptr_test, int res_test)
{
    printf(ANSI_COLOR_RED "-----------------------------------------------------------------\n");
    printf("ERROR IN TEST:\n");
    printf("PROGRAM OUTPUT: x1 = %g, x2 = %g, NOR = %d\n", ptr_test->x1, ptr_test->x2, res_test);
    printf("CORRECT OUTPUT: x1 = %g, x2 = %g, NOR = %d\n-----------------------------------------------------------------" ANSI_COLOR_RESET "\n", ptr_test->ans_x1, ptr_test->ans_x2, (int)ptr_test->result);
}

void test()
{
    size_t length = 0;

    struct parametrs* ptr_test = (struct parametrs*)tests_from_txt(&length);    

    for (size_t i = 0; i < length; ++i)
    {
        int res_test = quadro_equation(&ptr_test[i]);
        number_of_test_with_error(&ptr_test[i], res_test);
    }

    printf("-----------------------------------------------------------------\n\n");

    free(ptr_test);
}