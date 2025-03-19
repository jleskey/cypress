/**
 * @file jstring.h
 * @author Joseph Leskey
 */

#ifndef J_STRING_H
#define J_STRING_H

/**
 * Gets the length of an expanded format string.
 *
 * @param[in] format The format string
 * @param[in] ... Parameters
 * @returns The length of the string
 */
int jlenf(const char *format, ...);

/**
 * Gets the length of an expanded format string.
 *
 * @param[in] string The string
 * @returns The length of the string
 */
int jlen(const char *string);


#endif // J_STRING_H
