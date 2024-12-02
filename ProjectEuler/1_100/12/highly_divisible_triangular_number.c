/*
The sequence of triangle numbers is generated by adding the natural numbers.
What is the value of the first triangle number to have over five hundred divisors?
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

#include "../../lib/numeracy_math.h"

int numbers_of_divisors(long int num)
{
    int i = 0;
    if (num == 1)
        return 1;
    for (long int mul = 1; mul * mul <= num; mul++)
    {
        if (num % mul == 0)
        {
            if (mul * mul == num)
            {
                i++; // Perfect square, count only once
            }
            else
            {
                i += 2; // Count both divisors
            }
        }
    }
    return i;
}

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/

    long int triangle_number = 0;

    for (long int k = 1; numbers_of_divisors(triangle_number) < 500; k++)
    {
        triangle_number += k;
    }

    printf("%ld\n", triangle_number);

    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);
    char *date_str = lib_get_current_date();
    printf("Solution date: %s\n", date_str);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.1506658 seconds
Solution date: 2024-11-12
THE END
*/