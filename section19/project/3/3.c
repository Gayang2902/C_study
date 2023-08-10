/* Modify the stackADT3.c file of Section 19.4 by adding an int member named len to the stack type structure. 
 * This member will keep track of how many items are currently stored in a stack. 
 * Add a new function named length that has a Stack parameter and returns the value of the len member. 
 * (Some of the existing functions in stackADT3. c will need to he modified as well.) 
 * Modify stackclient. so that it calls the length function (and displays the value that it returns) after each operation that modifies a stack. 
 */

#include <stdio.h>
#include "stack-ADT.h"

int main(void)
{
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    printf("stack s1 has [%d] items\n", length(s1));

    push(s1, 2);
    printf("stack s1 has [%d] items\n", length(s1));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("stack s1 has [%d] items\n", length(s1));

    push(s2, n);
    printf("stack s2 has [%d] items\n", length(s2));

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    printf("stack s1 has [%d] items\n", length(s1));

    push(s2, n);
    printf("stack s2 has [%d] items\n", length(s2));

    destroy(s1);

    while (!is_empty(s2)) {
        printf("Popped %d from s2\n", pop(s2));
        printf("stack s2 has [%d] items\n", length(s2));
    }

    push(s2, 3);
    printf("stack s2 has [%d] items\n", length(s2));

    make_empty(s2);
    printf("stack s2 has [%d] items\n", length(s2));
    
    if (is_empty(s2)) 
        printf("s2 is empty\n");
    else 
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}