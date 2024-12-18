/*
<p>The prime factors of $13195$ are $5, 7, 13$ and $29$.</p>
<p>What is the largest prime factor of the number $600851475143$?</p>
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../lib/prime_number.h"

uint64_t const BOUNDARY = 600851475143;// 4 millions

int main()
{

    uint32_t largest_prime = 0;
    uint64_t total = 1;

    for (uint32_t i = 1; i <= BOUNDARY; i++){
        if (lib_is_prime_below_32bit(i)){
            if(BOUNDARY%i == 0){
                total *= i;
                if (total == BOUNDARY){
                    largest_prime = i;
                    break;
                }
                else if(total > BOUNDARY){
                    break;
                }
            }
        }
    }
    

    printf("TOTAL %lld \r\n", largest_prime);
    printf("TOTAL %lld \r\n", total);
    printf("The end \r\n");
    return 0;
}