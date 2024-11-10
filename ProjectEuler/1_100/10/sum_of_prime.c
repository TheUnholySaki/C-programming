/*
dif between sum of sqr and sqr of sum for first 100 natrual number
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

#include "../../lib/prime_number.h"

uint64_t const BOUNDARY = 20; // 4 millions

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/
    uint64_t total = 0;
    for (uint32_t i = 2; i<= 2000000; i++) {
        if(lib_is_prime_below_32bit(i)){
            total += i;
        }
    }
    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("total %lld \n", total);
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.1154026 seconds
total 142913828922
THE END
*/