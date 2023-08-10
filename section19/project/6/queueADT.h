#ifndef __QUEUEADT_H__
#define __QUEUEADT_H__

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue queue_create(int size);

void queue_destroy(Queue q);

void queue_append(Queue q, Item i);

void queue_remove_head(Queue q);

Item queue_head(Queue q);

Item queue_last(Queue q);

bool queue_is_empty(Queue q);

#endif