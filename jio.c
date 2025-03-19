/**
 * @file jio.c
 * @author Joseph Leskey
 */

#include <stdio.h>
#include <stdarg.h>

void jprintn(const char *format, const int times, ...)
{
    va_list args;
    va_start(args, times);

    for (int i = 0; i < times; i++) {
        printf(format, args);
    }

    va_end(args);
}
