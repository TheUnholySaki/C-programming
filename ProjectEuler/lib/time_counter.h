/*==================================================
LIB:


====================================================*/
#ifndef __TIMER_COUNTER_H
#define __TIMER_COUNTER_H


#include <stdio.h>
#include <windows.h>

void start_time(LARGE_INTEGER *start, LARGE_INTEGER *frequency) {
    QueryPerformanceFrequency(frequency);  // Get the frequency of the high-resolution counter
    QueryPerformanceCounter(start);        // Record the start time
}

double stop_time(LARGE_INTEGER *start, LARGE_INTEGER *frequency) {
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);         // Record the end time
    return (double)(end.QuadPart - start->QuadPart) / frequency->QuadPart;
}

#endif //__TIMER_COUNTER_H
