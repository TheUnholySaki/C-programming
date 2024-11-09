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

#include "../lib/variable_conversion.h"
#include "../lib/prime_number.h"

uint64_t const BOUNDARY = 20; // 4 millions

int main()
{
    uint64_t total = 1;
    for (int i = 2; i <= BOUNDARY; i++) {
        if(lib_is_prime_below_32bit(i)) {
            uint64_t factor = i;
            uint64_t temp = i;
            while(temp <= BOUNDARY) {
                temp *= factor;
            }
            temp /= factor;
            total *= temp;
        }
    }

    printf("%d\n", total);

    printf("THE END\n");
    return 0;
}