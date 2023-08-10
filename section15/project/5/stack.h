#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef STACK_H

#define STACK_H

void make_empty(void);
bool is_empty(void);
bool is_full(void);
bool push(char item);
char pop(void);
void reverse_polish_notation(char);
void stack_overflow();
void stack_underflow();

#endif