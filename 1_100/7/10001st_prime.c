/*
What is the
10001st prime number?
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

#include "../../lib/prime_number.h"

uint64_t const BOUNDARY = 10001; // 4 millions

int main()
{
    
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/
    uint32_t num = 2;
    uint32_t i = 0;
    while (true)
    {
        if (lib_is_prime_below_32bit(num))
        {
            i++;
        }
        if (i == BOUNDARY)
        {
            break;
        }
        num++;
    }

    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("results: %ld\n", num);
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.0018348 seconds
results: 104743
THE END
*/