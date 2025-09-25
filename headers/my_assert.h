#ifndef MY_ASSERT_H
#define MY_ASSERT_H

void my_assert(bool condition, const char* name_file, int line_of_file);

#ifndef NDEBUG
#define MY_ASSERT(condition) my_assert((condition), __FILE__, __LINE__);
#else
#define MY_ASSERT(condition)
#endif

#endif