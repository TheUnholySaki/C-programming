#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/*
If we list all the natural numbers below 10
 that are multiples of 3
 or 5
, we get 3,5,6, 9
. The sum of these multiples is 
. 23

Find the sum of all the multiples of 
 3 or 5 
 below 1000
.
Recovery Key:
2200097-LO1Koh0Hkfx4y2TjdwMAZ6b9dqsTHFlhJl4D0zGW
Direct Link:
https://projecteuler.net/recovery=2200097-LO1Koh0Hkfx4y2TjdwMAZ6b9dqsTHFlhJl4D0zGW
Generated:
Sun, 3 Nov 2024, 04:19.27

*/

#define BOUNDARY 1000
#define NUM1 3
#define NUM2 5

typedef struct
{
    uint8_t first_e;
    uint8_t second_e;
} input_t;

int main()
{
    input_t element;
    element.first_e = NUM1;
    element.second_e = NUM2;

    bool found_flag;
    uint32_t total = 0 ;
    for (int i = 0; i < BOUNDARY; i++)
    {
        if (i%element.first_e == 0 || i%element.second_e == 0) {
            found_flag = true;
        }
        if (found_flag)
        {
            total += i;
            found_flag = !found_flag;
        }
    }
    printf("TOTAL %ld \r\n", total);
    return 0;
}