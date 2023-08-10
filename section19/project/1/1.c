/* Modify Programming Project I from Chapter 10 so that it uses the stack ADT described in Section 19.4. 
 * You may use any of the implementations of the ADT described in that section. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack-ADT.h"

void suc(void)
{
    printf("Parentheses/braces are nested properly\n");
    exit(EXIT_SUCCESS);
}

void fail(void)
{
    printf("Parentheses/braces are not nested properly\n");
    exit(EXIT_FAILURE);
}

int main(void)
{
    char ch;
    bool result = true;
    Stack s = create_stack();

    printf("Enter parentheeses and/or braces: ");
    for (;;) {
        ch = (char)getchar();
        if (ch == '\n')
            break;
        switch (ch) {
            case '(':
                push(s, ch);
                break;
            case '{':
                push(s, ch);
                break;
            case ')':
                if (pop(s) != '(')
                    fail();
                break;
            case '}':
                if (pop(s) != '{') 
                    fail();
                break;
        }
    }
    if (!is_empty(s))
        fail();
    suc();
}