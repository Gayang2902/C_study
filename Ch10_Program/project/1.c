#include <stdbool.h>    /* C99에서만 가능 */
#include <stdio.h>

#define STACK_SIZE (100)

/* 외부변수 */
char g_contents[STACK_SIZE];
int g_top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
bool push(char);
char pop(void);

int main(void)
{
    char ch;
    bool result;

    printf("Enter parentheeses and/or braces: ");
    for (;;) {
        ch = (char)getchar();
        if (ch == '\n') {
            result = is_empty();
            break;
        }
        if (!push(ch)) {
            result = false;
            break;
        }
    }
    printf("Parentheses/braces are ");
    if (result == true) {
        printf("nested properly\n");
    } else {
        printf("not nested properly\n");
    }
    
    return 0;
}

void make_empty(void)
{
    g_top = 0;
}

bool is_empty(void)
{
    return g_top == 0;
}

bool is_full(void)
{
    return g_top == STACK_SIZE;
}

bool push(char item)
{
    char check;
    if (is_full()) {
        return false;
    } else {
        if (item == ')') {
            if (is_empty()) {
                return false;
            }
            check = pop();
            if (check != '(') {
                return false;
            }
            return true;
        } else if (item == '}') {
            if (is_empty()) {
                return false;
            } 
            check = pop();
            if (check != '{') {
                return false;
            }
            return true;
        }
        g_contents[g_top++] = item;
        return true;
    }
        
}

char pop(void)
{
    if (is_empty()) {
        return 0;
    } else {
        return g_contents[--g_top];
    }
}