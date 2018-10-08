#include "stack_unit_testing.h"


//==========__MASSIVE_PUSH__===============
// Does numerous pushes without checking the process
int Unittest_stack_massive_push(struct Stack* st, int num)
{
    printf("pushing: target: %d; completed: \n", num);
    int i = 0, printed = 0, del = num;
    for(int sign = -1; i < num; ++i, sign = -sign)
    {
        for(int j = 0; j < printed; ++j)
            printf("\b");

        if(Stack_push(st, i * sign) == ERROR)
        {
            printf("["RED"failed"RESET"]\n");
            return i;
        }

        if((i + 1) *+ 10 == del)
        {
            printed = printf(" %d%%", del * 10 / num);
            del += num;
        }
    }
    for(int j = 0; j < printed; ++j)
        printf("\b");
    printf("[ "GREEN"done"RESET" ]\n");
    return i;
}

//==========__MASSIVE_POP__================
// Does numerous popes without checking the process
int Unittest_stack_massive_pop(struct Stack* st, int num)
{
    printf("poping : target: %d; completed: \n", num);
    int i = 0, printed = 0, del = num, a;
    for(int sign = -1; i < num; ++i, sign = -sign)
    {
        for(int j = 0; j < printed; ++j)
            printf("\b");

        if(Stack_pop(st, &a) == ERROR)
        {
            printf("["RED"failed"RESET"]\n");
            return i;
        }

        if((i + 1) * 10 == del)
        {
            printed = printf(" %d%%", del * 10 / num);
            del += num;
        }
    }
    for(int j = 0; j < printed; ++j)
        printf("\b");
    printf("[ "GREEN"done"RESET" ]\n");
    return i;
}

//==========__UNIT_TESTING_PROCESS__=======
// Runs tests allowing to ensure that stack works correctly
void stack_unit_testing(void)
{
    struct Stack st = {};

    if(CHECK_MAXSIZE)
    { // max size testing
        printf("\nUNITTESTING==> MAX SIZE TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        UNITTEST(Unittest_stack_massive_push(&st, 10000), 10000);
        UNITTEST(Unittest_stack_massive_pop (&st, 10000), 10000);
    }

    if(CHECK_NEGATIVE_SIZE)
    { // size < 0
        printf("\nUNITTESTING==> SIZE TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        st.size = -1;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    if(CHECK_NEGATIVE_CAPACITY)
    { // capacity < 0
        printf("\nUNITTESTING==> CAPACITY TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        st.capacity = -1;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    if(CHECK_BAD_HASH)
    { // bad hash
        printf("\nUNITTESTING==> ITEM CHANGE TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        Stack_push(&st, 42);
        Stack_push(&st, 42);
        Stack_push(&st, 42);
        Stack_push(&st, 42);

        st.items[2] = 43;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    if(CHECK_EXCHANGE_HASH)
    { // hash exchange
        printf("\nUNITTESTING==> ITEM EXCHANGE TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        Stack_push(&st, 42);
        Stack_push(&st, 42);
        Stack_push(&st, 43);
        Stack_push(&st, 42);

        st.items[0] = 43;
        st.items[3] = 42;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    if(CHECK_CANARY)
    { // check bad canary
        printf("\nUNITTESTING==> CANARY TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        Stack_push(&st, 1);
        Stack_push(&st, 2);

        st.data[0] = 3;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    if(CHECK_CANARY_2)
    { // check canary double change
        printf("\nUNITTESTING==> SYMMERTY CANARY TEST\n");
        Stack_construct(st);
        st.using_state = TESTING;

        Stack_push(&st, 111);
        Stack_push(&st, 222);

        st.items[-1] = 3;
        st.items[st.capacity] = 3;
        UNITTEST(Stack_push(&st, 42), ERROR);
    }

    Stack_destruct(&st);
    return;
}
