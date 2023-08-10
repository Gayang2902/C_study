#include <stdlib.h>
#include <stdio.h>
#include "queueADT.h"

struct queue_type {
    Item contents[QUEUE_SIZE];
    // first empty slot
    int empty_index;
    // next item to be removed
    int removal_index;
    // number of items in the queue
    int num_of_items;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: malloc failed");

    q->empty_index = 0;
    q->removal_index = 0;
    q->num_of_items = 0;

    return q;
}

void queue_destroy(Queue q)
{
    free(q);
}

void queue_append(Queue q, Item i)
{
    if (q->num_of_items == QUEUE_SIZE) {
        printf("Error: queue is full\n");
        return;
    }

    q->contents[q->empty_index] = i;
    q->empty_index = ((q->empty_index + 1) == QUEUE_SIZE) ? 0 : q->empty_index + 1;
    q->num_of_items++;
}

void queue_remove_head(Queue q)
{
    if (queue_is_empty(q)) {
        printf("Error: queue is empty\n");
        return;
    }
    q->removal_index++;
    q->num_of_items--;
}

Item queue_head(Queue q)
{
    if (queue_is_empty(q)) {
        printf("Error: queue is empty\n");
        return -1;
    }
    return q->contents[q->removal_index];
}

Item queue_last(Queue q)
{
    if (queue_is_empty(q)) {
        printf("Error: queue is empty\n");
        return -1;
    }
    if (q->empty_index == 0)
        return q->contents[QUEUE_SIZE - 1];
    else 
        return q->contents[q->empty_index - 1];
}

bool queue_is_empty(Queue q)
{
    return q->num_of_items == 0;
}