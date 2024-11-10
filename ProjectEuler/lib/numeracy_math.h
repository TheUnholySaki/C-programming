/*==================================================
LIB:


====================================================*/
#ifndef __NUMERACY_MATH_H
#define __MUMERACY_MATH_H

#include <stdio.h>
#include <stdint.h>

uint32_t lib_sum_of_squares(int *arr, uint32_t size)
{
    uint32_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i] * arr[i];
    }
    return sum;
}

uint32_t lib_square_of_sum(int *arr, uint32_t size)
{
    uint32_t sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum * sum;
}

uint32_t lib_sum_of_squares_natural_num(uint32_t n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

uint32_t lib_square_of_sum_natural_num(uint32_t n)
{
    return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}

#endif //__NUMERACY_MATH_H