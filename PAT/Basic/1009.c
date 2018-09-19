#include <stdio.h>

int main()
{
    char str[100][100];
    int i;
    for (i = 0; scanf("%s", str[i]) != EOF; ++i);
    for (--i; i >= 0; --i)
    {
        printf("%s", str[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
