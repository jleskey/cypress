/**
 * @file conversions.h
 * @author Joseph Leskey
 */

#include <stdlib.h>

#define J_INT_STRING_SIZE 12
#define J_UINT_STRING_SIZE 11
#define J_PTR_STRING_SIZE 23

/**
 * Writes an integer to the given string
 *
 * @param[out] endpoint The output string
 * @param[in] length The length of the output string
 * @param[in] integer The integer to write
 */
void intToString(char *endpoint, int length, int integer);

/**
 * Writes an unsigned integer to the given string
 *
 * @param[out] endpoint The output string
 * @param[in] length The length of the output string
 * @param[in] integer The unsigned integer to write
 */
void uintToString(char *endpoint, int length, unsigned int integer);

/**
 * Writes an address to the given string
 *
 * @param[out] endpoint The output string
 * @param[in] length The length of the output string
 * @param[in] address The address to write
 */
void ptrToString(char *endpoint, int length, void *ptr);
