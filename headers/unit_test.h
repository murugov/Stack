#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "square_solver.h"
#include "struct_parametrs.h"
#include "colors.h"

void test();
int comparison(struct parametrs* ptr_test, int res_test);
void warning_output(struct parametrs* ptr_test, int res_test);
void number_of_test_with_error(struct parametrs* ptr_test, int res_test);
void* tests_from_txt(size_t* ptr_length);
void enter_test(double* ptr_data, struct parametrs* ptr_test, size_t length_data);

#endif