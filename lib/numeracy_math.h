/*==================================================
LIB:
    Numeracy Math Library

    This library provides functions for calculating:
    - The sum of squares for an array of integers or the first 'n' natural numbers
    - The square of the sum for an array of integers or the first 'n' natural numbers

    Functions included:
    - lib_sum_of_squares: Sum of squares for elements in an array
    - lib_square_of_sum: Square of the sum of elements in an array
    - lib_sum_of_squares_natural_num: Sum of squares of the first 'n' natural numbers
    - lib_square_of_sum_natural_num: Square of the sum of the first 'n' natural numbers
====================================================*/

#ifndef __NUMERACY_MATH_H
#define __NUMERACY_MATH_H

#include <stdio.h>
#include <stdint.h>

typedef uint32_t *num_array;

/**
 * Calculates the sum of squares for an array of integers.
 *
 * @param arr Pointer to the array of integers.
 * @param size Number of elements in the array.
 * @return The sum of squares of the array elements.
 */
uint32_t lib_sum_of_squares(int *arr, uint32_t size)
{
    uint32_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i] * arr[i]; // Square each element and add to sum
    }
    return sum;
}

/**
 * Calculates the square of the sum of an array of integers.
 *
 * @param arr Pointer to the array of integers.
 * @param size Number of elements in the array.
 * @return The square of the sum of the array elements.
 */
uint32_t lib_square_of_sum(int *arr, uint32_t size)
{
    uint32_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i]; // Accumulate the sum of all elements
    }
    return sum * sum; // Return the square of the total sum
}

/**
 * Calculates the sum of squares of the first 'n' natural numbers.
 *
 * @param n The number of natural numbers to consider.
 * @return The sum of squares of the first 'n' natural numbers.
 */
uint32_t lib_sum_of_squares_natural_num(uint32_t n)
{
    // Formula: n * (n + 1) * (2 * n + 1) / 6
    return n * (n + 1) * (2 * n + 1) / 6;
}

/**
 * Calculates the square of the sum of the first 'n' natural numbers.
 *
 * @param n The number of natural numbers to consider.
 * @return The square of the sum of the first 'n' natural numbers.
 */
uint32_t lib_square_of_sum_natural_num(uint32_t n)
{
    // Formula: (n * (n + 1) / 2)^2
    return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}

uint32_t lib_collatz_sequence(uint32_t start_num)
{
    uint32_t num = start_num;
    uint32_t i = 0;
    while (true)
    {
        i++;
        if (num % 2 == 0)
        {
            num = num >> 1;
        }
        else
        {
            num = num * 3 + 1;
        }

        if (num == 1)
        {
            break;
        }
    }
    return i;
}

uint64_t lib_factorial(uint64_t num)
{
    if (num < 0)
        num = -num;
    if (num <= 1)
        return 1;
    return num * lib_factorial(num - 1);
}

uint64_t lib_lattice_path(uint32_t o_x, uint32_t o_y, uint32_t des_x, uint32_t des_y)
{
    uint64_t m = abs(des_x - o_x);
    uint64_t n = abs(des_y - o_y);
    return (uint64_t)lib_factorial(m + n) / (lib_factorial(m) * lib_factorial(n));
}

#endif // __NUMERACY_MATH_H
