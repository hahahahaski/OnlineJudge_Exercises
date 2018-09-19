#include <stdio.h>

int getP(int a, int da)
{
    int pa = 0;
    while (a)
    {
        if (a % 10 == da)
            pa = pa * 10 + da;
        a /= 10;
    }
    return pa;
}

int main()
{
    int a, da, b, db;
    scanf("%d%d%d%d", &a, &da, &b, &db);
    printf("%d", getP(a, da) + getP(b, db));
    return 0;
}
