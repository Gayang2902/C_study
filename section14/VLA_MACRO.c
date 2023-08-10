#include <stdio.h>

#define TEST(condition, ...) ((condition) ? \
    printf("Passed test: %s\n", #condition) :\
    printf(__VA_ARGS__))

int main(void)
{
    int vol;
    int m_vol;

    printf("Input vol: ");
    scanf("%d", &vol);
    printf("Input m_vol: ");
    scanf("%d", &m_vol);

    TEST(vol <= m_vol, "Voltage %d exceeds %d\n", vol, m_vol);

    return 0;
}