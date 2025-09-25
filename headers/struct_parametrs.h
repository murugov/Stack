#ifndef STRUCT_PARAMETRS_H
#define STRUCT_PARAMETRS_H

enum {INFINITY_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS, IMAGINARY_ROOTS, VERDICT_OK = 0, VERDICT_WARNING, NOT_END_FILE = 1};

typedef double coef_t;
typedef double root_t;
typedef double res_t;

struct parametrs {
    coef_t a, b, c;
    root_t x1, x2, ans_x1, ans_x2;
    res_t result;
};

#endif