#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char ch;
    int i, j, k;
    scanf("%d %c", &n, &ch);
    for (i = 1; 2 * i * i - 1 <= n; ++i);
    --i;
    for (j = i; j >= 1; --j)
    {
        for (k = 1; k <= i - j; ++k)
            printf(" ");
        for (k = 1; k <= 2 * j - 1; ++k)
            printf("%c", ch);
        printf("\n");
    }
    for (j = 2; j <= i; ++j)
    {
        for (k = 1; k <= i - j; ++k)
            printf(" ");
        for (k = 1; k <= 2 * j - 1; ++k)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d\n", n - 2 * i * i + 1);
    return 0;
}
