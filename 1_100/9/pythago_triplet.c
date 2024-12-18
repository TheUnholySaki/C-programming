/*
pythagod triplet that a + b +c = 1000
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../lib/time_counter.h"

uint64_t const BOUNDARY = 20; // 4 millions


int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/
    int a, b, c;
    int m, n;
    for (m = 1; m < 500; m++) {
        // Calculate n based on m
        if (500 % m == 0) { // Ensure 500 / m is an integer
            n = 500 / m - m;
            
            if (n > 0 && n < m) { // Ensure n is positive and less than m
                // Generate the triplet
                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;

                // Check if it satisfies a + b + c = 1000
                if (a + b + c == 1000) {
                    printf("The Pythagorean triplet is: a = %d, b = %d, c = %d\n", a, b, c);
                    printf("Their product is: %d\n", a * b * c);
                    break;
                }
            }
        }
    }

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
The Pythagorean triplet is: a = 375, b = 200, c = 425
Their product is: 31875000
Execution time: 0.0029006 seconds
THE END
*/