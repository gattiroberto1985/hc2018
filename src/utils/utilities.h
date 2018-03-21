#ifndef UTILITIES_H
#define UTILITIES_H


#define FALSE 1
#define TRUE  0
#include <string.h>
#include <stdio.h>

// Defining boolean type (as alias of int :) )
typedef int bool;

// Function to print and make new line
void println(char* str);

// Function to replace a part of a string inside another string
char* string_replace(char const * const original, char const * const pattern, char const * const replacement);

#endif
