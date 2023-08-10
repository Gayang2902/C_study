/* Modify the stackADT.h and stackADT3.c files of Section 19.4 
 * so that a stack stores values of type void *, as described in Section 19.5: 
 * the Item type will no longer be used. 
 * Modify stackclient.c so that it stores pointers to strings in the s1 and s2 stacks.*/

#include <stdio.h>
#include "stack-ADT.h"

int main(void)
{
    Stack s1, s2;
    char *str;

    s1 = create();
    s2 = create();

    push(s1, "one");
    push(s1, "two");

    str = (char*)pop(s1);
    printf("Popped %s from s1\n", str);
    push(s2, str);
    str = (char*)pop(s1);
    printf("Popped %s from s1\n", str);
    push(s2, str);

    destroy(s1);

    while (!is_empty(s2))
        printf("Popped %s from s2\n", (char*)pop(s2));

    push(s2, "three");
    make_empty(s2);
    if (is_empty(s2)) 
        printf("s2 is empty\n");
    else 
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}