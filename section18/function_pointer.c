#include <stdio.h>

void print_hello(void)
{
    printf("Hello World!\n");
}

void (*return_function_pointer_returnvoid_parametervoid(void (*function)(void)))(void)
{
    return function;
}

int main(void)
{
    void (*fp)(void) = return_function_pointer_returnvoid_parametervoid(print_hello);

    (*fp)();

    return 0;
}