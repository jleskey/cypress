/**
 * @file jstring.c
 * @author Joseph Leskey
 */

#include <stdio.h>
#include <stdarg.h>

int jlength(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int size = vsnprintf(NULL, 0, format, args);

    va_end(args);

    return size;
}
