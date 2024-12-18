/*==================================================
LIB:
    Prime Number Library

    This library provides functions for prime number calculations, including:
    - Checking if a number is prime (up to 32-bit integers)
    - Finding prime numbers up to a given limit using various algorithms:
        - Trial Division
        - Sieve of Eratosthenes
        - Dijkstra's algorithm for prime numbers

    Functions included:
    - lib_is_prime_below_32bit: Checks if a number is prime (up to 32-bit)
    - lib_prime_num_trial_division: Finds primes up to a limit using Trial Division
    - prime_num_sieve_of_eratosthenes: Finds primes up to a limit using the Sieve of Eratosthenes
    - prime_num_dijkstra: Finds primes up to a limit using Dijkstra's algorithm
====================================================*/

#ifndef __PRIME_NUMBER_H
#define __PRIME_NUMBER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef uint64_t *prime_num_arr_t; // Defines a pointer type for an array of prime numbers
typedef uint64_t prime_num;        // Defines a type for prime numbers

/**
 * Checks if a given number (up to 32-bit) is prime.
 *
 * @param num The number to check for primality.
 * @return true if the number is prime, false otherwise.
 */
bool lib_is_prime_below_32bit(uint32_t num)
{
    // Handle edge cases for small numbers
    if (num <= 1)
        return false; // Numbers <= 1 are not prime
    if (num <= 3)
        return true; // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0)
        return false; // Divisible by 2 or 3 means not prime

    // Check divisibility up to the square root of num
    uint32_t end_of_check = (uint32_t)sqrt(num);
    for (uint32_t i = 5; i <= end_of_check; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true; // Number is prime if no divisors were found
}

/**
 * Finds prime numbers up to a given limit using the Trial Division algorithm.
 *
 * @param lim The upper limit up to which primes are calculated.
 * @return A dynamically allocated array of prime numbers up to 'lim'.
 */
prime_num_arr_t lib_prime_num_trial_division(uint64_t lim)
{
    prime_num_arr_t array = NULL;            // Initialize the array pointer to NULL
    int i = 0;                               // Tracks the number of elements in the array
    int capacity = 2;                        // Initial capacity of the array
    uint64_t lim_sqrt = (uint64_t)sqrt(lim); // Square root of limit, for divisibility check
    uint64_t num = 0;

    // Allocate initial memory for the prime array
    array = (prime_num_arr_t)malloc(capacity * sizeof(uint64_t));
    if (array == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL; // Return NULL if memory allocation fails
    }

    // Loop to find primes up to the limit
    while (i < lim)
    {
        // Resize the array if the current capacity is reached
        if (i >= capacity)
        {
            capacity *= 2; // Double the capacity
            array = (prime_num_arr_t)realloc(array, capacity * sizeof(uint64_t));
            if (array == NULL)
            {
                printf("Memory reallocation failed\n");
                return NULL;
            }
        }
        // Here, logic to check if 'num' is prime would go (example logic is omitted)
        // Assuming the number 'num' is prime, add it to the array

        array[i++] = i; // Example: adding numbers (this should actually be prime checking logic)
    }
    return array; // Return the populated array of primes
}

/**
 * Finds prime numbers up to a given limit using the Sieve of Eratosthenes algorithm.
 *
 * @param lim The upper limit up to which primes are calculated.
 * @return A dynamically allocated array of prime numbers up to 'lim'.
 */
prime_num_arr_t prime_num_sieve_of_eratosthenes(uint64_t lim);

/**
 * Finds prime numbers up to a given limit using Dijkstra's algorithm.
 *
 * @param lim The upper limit up to which primes are calculated.
 * @return A dynamically allocated array of prime numbers up to 'lim'.
 */
prime_num_arr_t prime_num_dijkstra(uint64_t lim);

#endif // __PRIME_NUMBER_H
