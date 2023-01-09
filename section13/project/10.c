/* <성 이름> 입력하면 <이름, 성(첫글자)>로 출력 */

#include <stdio.h>

void reverse_name(char *name);

int main(void)
{
    char name[41];
    char *p = name;
    char ch;

    printf("Enter a first and last name: ");

    while ((ch = getchar()) != '\n' && p < name + 40) {
        *(p++) = ch;
    }
    *p = '\0';
    
    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name;
    char *q = name;
    char inintial;

    while (*p == ' ') {
        p++;
    }
    inintial = *p;
    while (*p && *p++ != ' ');
    while (*p == ' ') {
        p++;
    }   
    while (*p && *p != '\n') {
        putchar(*p++);
    }
    printf(", %c\n", inintial);
}