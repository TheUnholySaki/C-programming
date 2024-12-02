#include <stdint.h>
#include <stdio.h>
#include "display.h"

extern int loop_counter;

void display_func(void)
{
    for (loop_counter; loop_counter < 5; loop_counter++)
    {
        printf("%d ", loop_counter);
    }
    return;
}