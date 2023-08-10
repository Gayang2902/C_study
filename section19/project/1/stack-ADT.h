#include <stdbool.h>

#ifndef __STACK_ADT_H__
#define __STACK_ADT_H__

#define MAX_CONTENTS (100)

typedef char Item;

typedef struct stack_type *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif