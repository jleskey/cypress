/**
 * @file conversions.c
 * @author Joseph Leskey
 */

#include "conversions.h"
#include <stdio.h>

void intToString(char *endpoint, int length, int integer) {
    snprintf(endpoint, length, "%d", integer);
}

void uintToString(char *endpoint, int length, unsigned int integer) {
    snprintf(endpoint, length, "%u", integer);
}

void ptrToString(char *endpoint, int length, void *ptr) {
    snprintf(endpoint, length, "%p", ptr);
}
