#include "is_zero.h"
#include "square_solver.h"
#include "my_assert.h"
#include <math.h>

double discriminat(struct parametrs* ptr_structure)
{
    //assert(ptr_stucture != NULL);
    MY_ASSERT(ptr_structure != NULL);

    double D = ptr_structure->b * ptr_structure->b - 4 * ptr_structure->a * ptr_structure->c;
    return D;
}

int quadro_equation(struct parametrs* ptr_structure)
{
    //assert(ptr_structure != NULL);
    MY_ASSERT(ptr_structure != NULL);

    if (is_zero(ptr_structure->a)) 
    {
        if (is_zero(ptr_structure->b)) 
            return (is_zero(ptr_structure->c)) ? INFINITY_ROOTS: NO_ROOTS;
        else {
            ptr_structure->x1 = -ptr_structure->c/ptr_structure->b;
            return ONE_ROOT;
        }
    }

    double D = discriminat(ptr_structure);

    if (is_zero(D))
    {
        if (is_zero(ptr_structure->b))
           ptr_structure->x1 = 0;
        else
            ptr_structure->x1 = -ptr_structure->b / (2 * ptr_structure->a);
        return ONE_ROOT;
    }
    else if(D < 0)
        return IMAGINARY_ROOTS;
    else {
        double x1 = (-ptr_structure->b + sqrt(D)) / (2 * ptr_structure->a);
        double x2 = (-ptr_structure->b - sqrt(D)) / (2 * ptr_structure->a);

        ptr_structure->x1 = (x1 > x2) ? x1: x2;
        ptr_structure->x2 = (x1 < x2) ? x1: x2;

        return TWO_ROOTS;
    }

}