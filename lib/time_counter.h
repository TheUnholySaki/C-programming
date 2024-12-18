/*==================================================
LIB:
    Timer Counter Library

    This library provides functions for timing code execution using
    the Windows high-resolution performance counter.

    Functions included:
    - start_time: Records the start time of a timer
    - stop_time: Calculates the elapsed time in seconds since start_time was called
====================================================*/

#ifndef __TIMER_COUNTER_H
#define __TIMER_COUNTER_H

#include <stdio.h>
#include <windows.h>

/**
 * Starts the timer by recording the current counter value and frequency.
 *
 * @param start Pointer to a LARGE_INTEGER structure to store the starting counter value.
 * @param frequency Pointer to a LARGE_INTEGER structure to store the counter frequency.
 */
void start_time(LARGE_INTEGER *start, LARGE_INTEGER *frequency)
{
    QueryPerformanceFrequency(frequency); // Get the frequency of the high-resolution counter
    QueryPerformanceCounter(start);       // Record the start time
}

/**
 * Stops the timer and calculates the elapsed time in seconds.
 *
 * @param start Pointer to a LARGE_INTEGER structure containing the starting counter value.
 * @param frequency Pointer to a LARGE_INTEGER structure containing the counter frequency.
 * @return The elapsed time in seconds as a double.
 */
double stop_time(LARGE_INTEGER *start, LARGE_INTEGER *frequency)
{
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end); // Record the end time
    return (double)(end.QuadPart - start->QuadPart) / frequency->QuadPart;
}

#include <stdio.h>
#include <time.h>

/**
 * Retrieves the current date in YYYY-MM-DD format.
 * @note The returned buffer is static and will be overwritten with each function call.
 *               This function is not thread-safe due to the use of a static buffer.
 * @return A pointer to a static buffer containing the date string in the format "YYYY-MM-DD".
 */
char *lib_get_current_date()
{
    static char date_str[11];

    time_t t = time(NULL);
    struct tm *local_time = localtime(&t);

    // Format the date as YYYY-MM-DD and store it in date_str

    sprintf(date_str, "%04d-%02d-%02d",
            local_time->tm_year + 1900, // Year since 1900
            local_time->tm_mon + 1,     // Month (0-11, so add 1)
            local_time->tm_mday);       // Day of the month

    return date_str;
}

#endif // __TIMER_COUNTER_H
