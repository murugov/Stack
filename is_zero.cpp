#include "is_zero.h"

int is_zero(double x)
{
    double epsilon = 0.00000001;

    if (fabs(x) < epsilon)
        return 1;
    return 0;
}