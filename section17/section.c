#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void)
{
    int *t = (int)malloc(sizeof(int));

    if (t == NULL) {
        puts("Ops");
    }

    return 0;
}