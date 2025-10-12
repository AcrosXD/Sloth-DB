#include "utils.h"

char* concat(unsigned int n, ...){
    size_t mem_to_alloc = 1; //Null char terminator added
    size_t offset = 0;
    //Using n as a ref value and letting i do the work (what a lazy ass)
    int i = n;

    //Init va list
    va_list args;
    va_start(args, n);
    //Compute the amount of memory needed (fuck for loops)
    do {
        mem_to_alloc += strlen(va_arg(args, char*));
        i--;
    } while(i != 0);
    //Allocate it
    char* res = malloc(mem_to_alloc);
    va_end(args);

    i = n;
    va_start(args, n);
    //Concatenate loop
    do {
        //Taking the string from the va list
        char* string = va_arg(args, char*);
        //Putting it in the final string shifted by the offset
        strcpy(res + offset, string);
        //The offset equals the current string length plus the sum of the previous ones
        offset += strlen(string);
        i--;
    } while(i != 0);
    va_end(args);
    
    return res;
}