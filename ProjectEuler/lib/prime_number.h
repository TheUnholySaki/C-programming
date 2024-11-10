/*==================================================
LIB:


====================================================*/
#ifndef __PRIME_NUMBER_H
#define __PRIME_NUMBER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef uint64_t *prime_num_arr_t;
typedef uint64_t prime_num;

bool lib_is_prime_below_32bit(uint32_t num);

/**
 * @def find prime number using trial division algorithm
 * @var (uint64_t) lim
 * @return uint32_t results
 */
prime_num_arr_t lib_prime_num_trial_division(uint64_t lim);



/**
 * @def find prime number using trial division algorithm
 * @var (uint64_t) lim
 * @return uint32_t results
 */
prime_num_arr_t prime_num_sieve_of_eratosthenes(uint64_t lim);




/**
 * @def find prime number using trial division algorithm
 * @var (uint64_t) lim
 * @return uint32_t results
 */
prime_num_arr_t prime_num_dijkstra(uint64_t lim);

bool lib_is_prime_below_32bit(uint32_t num)
{
    // preliminary
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num%2 == 0 || num%3 == 0) return false;

    uint32_t end_of_check = (uint32_t) sqrt(num);
    for (uint32_t i = 5; i <= end_of_check; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

prime_num_arr_t lib_prime_num_trial_division(uint64_t lim)
{
    prime_num_arr_t array = NULL; // Start with a NULL pointer
    int i = 0;                    // Current number of elements
    int capacity = 2;             // Initial capacity (can be any positive number)
    uint64_t lim_sqrt = (uint64_t)sqrt(lim);
    uint64_t num = 0;

    array = (prime_num_arr_t)malloc(capacity * sizeof(uint64_t));
    // Simulate adding elements dynamically
    while (i < lim)
    {
        // Check if resizing is needed
        if (i >= capacity)
        {
            // Double the capacity
            capacity *= 2;
            array = (prime_num_arr_t)realloc(array, capacity * sizeof(uint64_t));
            if (array == NULL)
            {
                printf("Memory reallocation failed\n");
                return NULL;
            }
        }
        // is_prime

        // Add the new element
        array[i++] = i; // Example: adding numbers 0, 1, 2, ...
    }
    return array;
}

#endif //__PRIME_NUMBER_H
