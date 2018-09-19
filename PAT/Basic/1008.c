#include <stdio.h>

int main()
{
    int n, m;
    int arr[100];
    int i, j, temp;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for (i = 1; i <= m; ++i)
    {
        temp = arr[n - 1];
        for (j = n - 1; j >= 1; --j)
            arr[j] = arr[j - 1];
        arr[0] = temp;
    }
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}
