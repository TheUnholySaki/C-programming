/*
lattice path, like in 3x3 grid, how many routes are there from 0,0 to 2,2.
In this case, 20x20
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "../../lib/time_counter.h"

#include "../../lib/numeracy_math.h"
uint64_t const BOUNDARY = 20; // 4 millions

uint32_t find_routes(int x,int y)
{
    uint32_t routes = 0;
    if (y > 0)
        routes += find_routes(x, y - 1);
    if (x > 0)
        routes += find_routes(x - 1, y);

    if (x == 0 && y == 0)
    {
        routes += 1;
        return routes;
    }
}

int main()
{
    LARGE_INTEGER start, frequency;
    start_time(&start, &frequency);
    /* ================PLACE YOUR FUNCTION HERE============*/

    printf("lib: %lld\n", lib_factorial(40));
    uint64_t result = lib_lattice_path(0, 0, 10, 10);

    /* ========================END========================*/
    double execution_time = stop_time(&start, &frequency);
    printf("Execution time: %.7f seconds\n", execution_time);
    char *date_str = lib_get_current_date();
    printf("Solution date: %s\n", date_str);

    /* ================PLACE YOUR PRINT OUT HERE============*/
    printf("results: %lld\n", find_routes(2,2));
    printf("THE END\n");
    return 0;
}

/*
Execution time: 0.5285441 seconds
Solution date: 2024-11-12
results: 837799
THE END
*/