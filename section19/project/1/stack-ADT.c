#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack-ADT.h"

struct stack_type {
    Item contents[MAX_CONTENTS];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create_stack(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: malloc failed");
    s->top = 0;
    return s;
}

void destroy_stack(Stack s)
{
    free(s);
}

void make_empty(Stack s)
{
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == MAX_CONTENTS;
}

void push(Stack s, Item i)
{
    if (is_full(s))
        terminate("Error in push: stack is fulled");
    s->contents[(s->top)++] = i;        
}

Item pop(Stack s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty");
    return s->contents[--(s->top)];
}