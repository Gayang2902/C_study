/* Starting from the queue.h header of Exercise I, create a file named queueADT.h that defines the following Queue type:
 * <typedef struct queue_type *Queue;>
 * queue type is an incomplete structure type. Create a file named queueADT.c 
 * that contains the full definition of queue_type as well as definitions for all the functions in queue.h. 
 * Use a fixed-length array to store the items in a queue (see Exercise 3(a)). 
 * Create a file named queueclient.c (similar to the stackclient. c file of Section 19.4) 
 * that creates two queues and performs operations on them. Be sure to provide create and destroy functions for your ADT. */

#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q = create_queue();

    insert_item(q, 1);
    insert_item(q, 2);
    insert_item(q, 3);
    insert_item(q, 4);
    insert_item(q, 5);

    insert_item(q, 10);

    printf("%d\n", return_first_item(q));
    printf("%d\n", return_last_item(q));

    remove_item(q);

    return 0;
}