/** \file stack_unit_testing.h
 */
#ifndef STACK_UNIT_TESTING_H_INCLUDED
#define STACK_UNIT_TESTING_H_INCLUDED

#include "stack.h"
#include <stdlib.h>

#define CHECK_MAXSIZE           (1)
#define CHECK_NEGATIVE_SIZE     (1)
#define CHECK_NEGATIVE_CAPACITY (1)
#define CHECK_BAD_HASH          (1)
#define CHECK_EXCHANGE_HASH     (1)
#define CHECK_CANARY            (1)
#define CHECK_CANARY_2          (1)

#define UNITTEST( condition, reference ) \
    { \
        int tmp_cond = condition; \
        if((tmp_cond) != (reference)) \
            printf("["RED"FAILED"RESET"] %s = %d, expected %d\n", #condition, tmp_cond, reference); \
        else \
            printf("[  "GREEN"OK"RESET"  ] %s = %d\n", #condition, reference); \
    }

//==========__MASSIVE_PUSH__===============
/** \brief Does numerous pushes without checking the process
 *
 * \param st struct Stack* [in] - stuck to push into
 * \param num int [in] - number of items to push
 * \return (num) - if all of (num) numbers were pushed; else int - the number of item that failed to be pushed
 *
 */
int Unittest_stack_massive_push(struct Stack* st, int num);

//==========__MASSIVE_POP__================
/** \brief Does numerous popes without checking the process
 *
 * \param st struct Stack* [in] - stuck to pop from
 * \param num int [in] - number of items to pe popped
 * \return (num) - if all of (num) numbers were poped; else int - the number of item that failed to be poped
 *
 */
int Unittest_stack_massive_pop(struct Stack* st, int num);

//==========__UNIT_TESTING_PROCESS__=======
/** \brief Runs tests allowing to ensure that stack works correctly
 */
void stack_unit_testing(void);

#endif // STACK_UNIT_TESTING_H_INCLUDED
