// argv의 첫번째 값은 프로그램의 이름, 마지막 값은 null pointer 이다.

#include <stdio.h>

int main(int argc, char *argv[])
{
    int arc = argc - 1;
    
    while (arc) {
        printf("%s ", argv[arc--]);
    }
    printf("\n");

    return 0;
}