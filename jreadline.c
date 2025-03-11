/**
 * @file jreadline.c
 * @author Joseph Leskey
 * @date 12 March 2025
 */

#include "jreadline.h"
#include <stdio.h>
#include <stdlib.h>

char *promptInput(char const *prompt)
{
    char *response = NULL;

    // We want to get useable input.
    while (!response || response[0] == '\0')
    {
        printf("%s ", prompt);

        response = jReadLine(stdin);

        // Handle EOF.
        if (response == NULL)
        {
            printf("^D\n");
            exit(EXIT_SUCCESS);
        }
    }

#if PROMPT_NEWLINE
    printf("\n");
#endif

    return response;
}

char *jReadLine(FILE *stream)
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
            // Set to overwrite trailing whitespace.
            if (prevC == ' ')
            {
                length--;
            }

            // Terminate the string.
            buffer[length] = '\0';
        }
        // We discard leading whitespace in whitespace pairs.
        else if (c != ' ' || (prevC != ' ' && length != 0))
        {
            buffer[length++] = c;
        }

        prevC = c;
    }

    return buffer;
}
