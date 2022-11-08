#include <stdio.h>
int main(void)
{
    int X, N, a, b, total=0;
    scanf("%d %d", &X, &N);
    for(; N>0; N--) {
        scanf(" %d %d", &a, &b);
        total += a*b;
    }
    if (total == X) printf("Yes\n");
    else printf("No\n");
    return 0;
}