/** \file main.c
 */

#include "stack.h"
#include "stack_unit_testing.h"

//VER_1
    //~system("start https://nani"); // what does this actually mean???
    //~-E for pre-compiling defines
    //~do progress bar (\b)
    //+UNIT testing
    //+remake pop as error occurencer
    //+printing locking
    //+dump = detailed info for programmer
    //+color texting
    //+ASSERT_OK as in presentation
    //+hash function

    //VER_2
    //+O(1) in push() and pop()
    //+screamer when error
    //+minor code improvements
    //+progress bar
    //+now this text is placed a bit higher
    //~oh look, a one-function-in-main-program

int main()
{
    stack_unit_testing();

    return 0;
}
