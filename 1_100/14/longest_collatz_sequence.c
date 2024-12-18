/*
collatz sequence
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../lib/time_counter.h"

#include "../../lib/numeracy_math.h"
uint64_t const BOUNDARY = 20; // 4 millions

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/

    uint32_t result = 0;
    uint32_t largest_chain = 0;
    uint32_t assoc_num = 0;
    for (uint32_t i = 2; i < 1000000; i++)
    {
        result = lib_collatz_sequence(i);
        // printf("length is %ld\n", result);
        if (result > largest_chain)
        {
            largest_chain = result;
            assoc_num = i;
        }
    }

    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);
    char *date_str = lib_get_current_date();
    printf("Solution date: %s\n", date_str);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("results: %lld\n", assoc_num);
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.5285441 seconds
Solution date: 2024-11-12
results: 837799
THE END
*/