#include <stdlib.h>
#include <stdio.h>
#include "queueADT.h"

struct queue_type {
    Item *contents;

    // first empty slot
    int empty_index;
    // next item to be removed
    int removal_index;
    // number of items in the queue
    int num_of_items;
    // size of queue (dynamically allocated array)
    int size_of_queue;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: malloc failed\n[queue create fail]");

    q->contents = malloc(sizeof(Item) * size);
    if (q->contents == NULL) 
        terminate("Error in create: malloc failed\n[queue->contents create fail]");

    q->empty_index = 0;
    q->removal_index = 0;
    q->num_of_items = 0;
    q->size_of_queue = size;

    return q;
}

void queue_destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void queue_append(Queue q, Item i)
{
    if (q->num_of_items == q->size_of_queue) {
        printf("Error: queue is full\n");
        return;
    }

    q->contents[q->empty_index] = i;
    q->empty_index = ((q->empty_index + 1) == q->size_of_queue) ? 0 : q->empty_index + 1;
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
        return q->contents[q->size_of_queue - 1];
    else 
        return q->contents[q->empty_index - 1];
}

bool queue_is_empty(Queue q)
{
    return q->num_of_items == 0;
}


Po point(선언) = ??-> 저는 point라는 변수를 만들겁니다. 근데 이 변수는 Po클래스를 이용해서 만들겁니다.
point(정의) = new(생성자 = class를 통해 instance를 생성함) Po(); -> 저는 아까 말한 변수를 Po라는 class를 통해 instance로 만들겁니다.
point.move(10, 10); -> 저는 Po라는 class를 통해 만들어낸 point라는 instance에게 message를 보낼겁니다.
message의 내용은 instance이름은 point.point라는 instance에서 사용할 기능(method)는 move입니다.
이 move라는 method에게 전달할 매개변수는 10과 10입니다.

point = new Po();

Po point; -> variable
point = new Po(); -> instance

리스트 -> 사용자는 인터페이스만 보고 씀

개발자는 구현할때
배열으로 구현
포인터로 구현

10 * 10 을 해주는 함수 tenxten

int tenxten(); -> 인터페이스

1 * 10;
1 + 1 + 1 + 1 +... 
-> 구현