/**
 * @file jreadline.h
 * @author Joseph Leskey
 * @date 18 March 2025
 */

#ifndef J_READ_LINE_H
#define J_READ_LINE_H

#include <stdio.h>
#include <stdbool.h>

/** The incrementation factor of dynamically allocated char arrays */
#define STRING_INCREMENT 16

/** Stategies for handling whitespace in input */
typedef enum JTrimmer
{
    /** Preserves all whitespace in input. */
    J_TRIM_PRESERVE,
    /** Trims whitespace at the beginning and end of input.*/
    J_TRIM_TRIM,
    /** Removes all occurences of double whitespace. */
    J_TRIM_REDUCE
} JTrimmer;

/**
 * Display prompt until the user inputs a useful value.
 *
 * @param[in] prompt The prompt to display
 * @param[in] trimmer Method for handling whitespace in input
 * @param[in] newline Whether or not to print a newline after user input
 * @returns A meaningful line of input from `stdin`
 */
char *promptInput(char const *prompt, JTrimmer trimmer, bool newline);

/**
 * Read a line from a given file descriptor
 *
 * @param[in] stream The file descriptor
 * @param[in] trimmer Method for handling whitespace in input
 * @returns The text of an user input line or `NULL` if EOF is reached
 */
char *jReadLine(FILE *stream, JTrimmer trimmer);

#endif // J_READ_LINE_H
