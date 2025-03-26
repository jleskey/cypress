/**
 * @file jtable.c
 * @author Joseph Leskey
 */

#include "table.h"
#include "io.h"
#include "string.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

JTableProperties jTableInit(int columns, ...)
{
    va_list args;
    va_start(args, columns);

    JTableProperties properties;

    properties.columns = columns;

    properties.widths = (int *)malloc(sizeof(int) * columns);

    for (int i = 0; i < columns; i++) {
        char *content = va_arg(args, char *);
        properties.widths[i] = jlen(content);
    }

    va_end(args);

    return properties;
}

void jTableAdjust(JTableProperties *properties, ...) {
    va_list args;
    va_start(args, properties);

    for (int i = 0; i < properties->columns; i++) {
        int size = va_arg(args, int);

        if (size > properties->widths[i]) {
            properties->widths[i] = size;
        }
    }

    va_end(args);
}

void jTableRow(JTableProperties *properties, ...)
{
    va_list args;
    va_start(args, properties);

    jTableBorder(properties);

    for (int i = 0; i < properties->columns; i++) {
        printf(i == 0 ? "| " : " | ");
        char *text = va_arg(args, char*);
        jTableColumn(properties->widths[i], text);
    }

    printf(" |");

    printf("\n");

    va_end(args);
}

void jTableColumn(const int width, const char *content)
{
    bool writing = true;

    for (int i = 0; i < width; i++) {
        char character;

        if (writing) {
            character = content[i];

            if (character == '\0') {
                character = ' ';
                writing = false;
            }
        } else {
            character = ' ';
        }

        printf("%c", character);
    }
}

void jTableBorder(JTableProperties *properties)
{
    printf("+");

    for (int i = 0; i < properties->columns; i++) {
        jprintn("-", properties->widths[i] + 2);
        printf("+");
    }

    printf("\n");
}
