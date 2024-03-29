#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack-ADT.h"  

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    struct node *top;
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
    s->top = NULL;
    return s;
}

void destroy_stack(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: malloc failed");

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack s)
{
    Item return_value;
    struct node *old_top;

    if (is_empty(s))
        terminate("Error in pop: stack is empty");

    old_top = s->top;
    s->top = old_top->next;
    return_value = old_top->data;
    free(old_top);

    return return_value;
}