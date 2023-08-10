#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueADT.h"   

struct node {
    Item item;
    struct node *next;
};

// head는 노드의 첫번째를 포인팅
// tail은 노드의 마지막을 포인팅

struct queue_type {
    struct node *head;
    struct node *tail;
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
    
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void queue_destroy(Queue q)
{
    while (!queue_is_empty(q))
        queue_remove_head(q);

    free(q);
}

void queue_append(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) 
        terminate("Error in apped: malloc failed");

    new_node->item = i;
    new_node->next = NULL;

    if (queue_is_empty(q)) {
        q->head = new_node;
        q->tail = new_node;
    }
    else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void queue_remove_head(Queue q)
{
    if (!queue_is_empty(q)) {
        struct node *removal_node = q->head;

        if (q->head == q->tail) {
            q->head = NULL;
            q->tail = NULL;
        } else
            q->head = q->head->next;
        free(removal_node);   
    } else 
        printf("q is empty!!\n");
}

Item queue_head(Queue q)
{
    if (!queue_is_empty(q))
        return q->head->item;
    else 
        printf("q is empty!!\n");
    return -1;
}

Item queue_last(Queue q)
{
    if (!queue_is_empty(q))
        return q->tail->item;
    else
        printf("q is empty!!\n");
    return -1;
}

bool queue_is_empty(Queue q)
{
    return q->head == NULL;
}