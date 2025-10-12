#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
    Concatenate n number of strings
    Parameters: Number of strings to concatenate, const char* to concatenate
    Returns: One char* of concatenated strings
*/
char* concat(unsigned int n, ...);