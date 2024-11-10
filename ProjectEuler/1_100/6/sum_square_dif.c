/*
dif between sum of sqr and sqr of sum for first 100 natrual number
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

#include "../../lib/numeracy_math.h"

uint64_t const BOUNDARY = 20; // 4 millions

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/

    uint32_t num_of_natural_num = 100;
    uint32_t sum_of_squares = lib_sum_of_squares_natural_num(num_of_natural_num);
    uint32_t square_of_sum = lib_square_of_sum_natural_num(num_of_natural_num);
    uint32_t dif = sum_of_squares - square_of_sum;
    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("results: %ld\n", dif);
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.0000000 seconds
results: -25164150
THE END
*/