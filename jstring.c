/**
 * @file jstring.c
 * @author Joseph Leskey
 */

#include "jstring.h"
#include <stdio.h>
#include <stdarg.h>

int jlenf(char *format, ...)
{
    va_list args;
    va_start(args, format);

    int size = vsnprintf(NULL, 0, format, args);

    va_end(args);

    return size;
}

int jlen(char *string) {
    int length = 0;
    while (string[++length] != '\0');
    return length;
}
