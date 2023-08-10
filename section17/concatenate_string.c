// strcat은 기존 string을 변형할 가능성이 존재
// 동적 메모리 할당을 이용해 안전한 strcat 만들기

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *concat(const char *s1, const char *s2)
{
    char *result;

    // c에서 char type 의 크기가 1로 보장되어 있기 때문에 sizeof를 쓰지 않고 배열의 길이만 따져도 된다.
    if ((result = malloc(strlen(s1) + strlen(s2) + 1)) == NULL) { 
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(void)
{
    char *p;

    puts((p = concat("abc", "def")));

    return 0;
}