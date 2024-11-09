/*Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with
 and
, the first
 terms will be: 1,2,3,5,...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

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

#define BOUNDARY 4000000 // 4 millions
#define NUM1 1
#define NUM2 2

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

    uint32_t total = NUM2;
    uint32_t pp_v = NUM1;
    uint32_t p_v = NUM2;
    uint32_t current_v;
    while (true)
    {
        /* Calculate current value*/
        current_v = p_v + pp_v;
        /* Check for boundary*/
        if (current_v >= BOUNDARY)
        {
            break;
        }
        if (current_v % 2 == 0)
        {
            total += current_v;
        }

        /* Parse previous and p-previous value*/
        pp_v = p_v;
        p_v = current_v;
    }
    printf("TOTAL %ld \r\n", total);
    return 0;
}