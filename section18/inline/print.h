#include <stdio.h>

#ifndef PRINT_H
#define PRINT_H

inline void print(void)
{
    printf("print success\n");
}

extern void print(void);

#endif