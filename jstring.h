/**
 * @file jstring.h
 * @author Joseph Leskey
 */

#ifndef J_STRING_H
#define J_STRING_H

#include <stdio.h>
#include <stdarg.h>

/**
 * Gets the length of an expanded format string.
 *
 * @param[in] format The format string
 * @param[in] ... Parameters
 * @returns The length of the string
 */
int jlength(const char *format, ...);

#endif // J_STRING_H
