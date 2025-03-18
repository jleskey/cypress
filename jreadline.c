/**
 * @file jreadline.c
 * @author Joseph Leskey
 * @date 18 March 2025
 */

#include "jreadline.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *promptInput(char const *prompt, JTrimmer trimmer, bool newline)
{
    char *response = NULL;

    // We want to get useable input.
    while (!response || response[0] == '\0')
    {
        free(response);

        printf("%s ", prompt);

        response = jReadLine(stdin, trimmer);

        // Handle EOF.
        if (response == NULL)
        {
            printf("^D\n");
            exit(EXIT_SUCCESS);
        }
    }

    if (newline)
    {
        printf("\n");
    }

    return response;
}

char *jReadLine(FILE *stream, JTrimmer trimmer)
{
    char *buffer = NULL;
    int size = 0;
    int length = 0;

    char prevC = '\0';
    char c = '\0';

    // Loop through all useful characters.
    while (c != '\n' && (c = fgetc(stream)) != EOF)
    {
        // We use `length + 1` to leave room for a null terminator.
        if (length + 1 >= size)
        {
            // We need to increase the buffer size.
            size += STRING_INCREMENT;

            // It would be a shame to lose the original buffer
            // reference if `realloc` fails. Let's avoid that.
            char *_buffer = realloc(buffer, sizeof(char) * size);
            if (!_buffer)
            {
                free(buffer);
                fprintf(stderr, "Memory allocation error.\n");
                return NULL;
            }
            buffer = _buffer;
        }

        if (c == '\n')
        {
            // If trimming is enabled, overwrite any trailing space.
            if (trimmer != J_TRIM_PRESERVE && prevC == ' ')
            {
                length--;
            }

            // Terminate the string.
            buffer[length] = '\0';
        }
        else if (
            // Non-whitespace characters
            c != ' ' ||
            // Whitespace preservation
            trimmer == J_TRIM_PRESERVE ||
            // Whitespace removal
            (
                // Whitespace trimming
                length != 0 &&
                // Whitespace reduction
                (trimmer != J_TRIM_REDUCE || prevC != ' ')))
        {
            buffer[length++] = c;
        }

        prevC = c;
    }

    return buffer;
}
