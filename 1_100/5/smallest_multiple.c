/*
2520 is the smallest number that can be divided by each of the numbers from
1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from
1 to 20.
?
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

#include "../../lib/variable_conversion.h"
#include "../../lib/prime_number.h"

uint64_t const BOUNDARY = 20; // 4 millions

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/

    uint64_t total = 1;
    for (int i = 2; i <= BOUNDARY; i++)
    {
        if (lib_is_prime_below_32bit(i))
        {
            uint64_t factor = i;
            uint64_t temp = i;
            /* is Least common multiple, we consider prime number exponential
             For example, from 1->20, prime number 2 can be factored to 2^4 = 16 < 20
            */
            while (temp <= BOUNDARY)
            {
                temp *= factor;
            }
            temp /= factor;
            total *= temp;
        }
    }

    
    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);
    
    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("%d\n", total);
    printf("THE END\n");
    return 0;
}