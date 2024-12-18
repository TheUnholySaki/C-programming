/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two
-digit numbers is 9009 = 91x99
.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../lib/variable_conversion.h"

uint64_t const BOUNDARY = 600851475143; // 4 millions

int main()
{
    int32_t num1 = 999;
    int32_t num2 = 999;
    int32_t largest_num = 0;
    for (int j = 0; j <= 999; j++)
    {
        for (int i = 0; i <= 999; i++)
        {
            uint32_t total = num1 * (num2 - i);
            string_t result = lib_int_to_str(total);
            if (lib_check_palindrome(&result))
            {
                if (total > largest_num) largest_num = total;
            }
        }
        num1--;
    }
    printf("largest %ld\n", largest_num);
    printf("THE END\n");
    return 0;
}