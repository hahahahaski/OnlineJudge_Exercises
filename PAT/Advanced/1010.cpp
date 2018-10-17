#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

long long x_to_d(const std::string& str, int radix)
{
    long long decimal = 0LL;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            decimal = decimal * radix + str[i] - 'a' + 10;
        else if (str[i] >= '0' && str[i] <= '9')
            decimal = decimal * radix + str[i] - '0';
    }
    return decimal;
}

int findMinRadix(const std::string & str)
{
    char ch = '0';
    for (int i = 0; i < str.size(); ++i)
        if (str[i] > ch)
            ch = str[i];
    if (ch >= '0' && ch <= '9')
        return std::max(2, ch - '0' + 1);
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 11;
}

long long d1;

long long bin_search(long long left, long long right, const std::string& str)
{
    if (left >= right)
        return left;
    long long mid = (left + right) / 2;
    long long d2 = x_to_d(str, mid);
    if (d2 >= d1)
        return bin_search(left, mid, str);
    return bin_search(mid + 1, right, str);
}

long long quick_pow(int a, int b)
{
    long long ret = 1;
    long long temp = a;
    for ( ; b; b >>= 1)
    {
        if (b & 1)
            ret *= temp;
        temp *= temp;
    }
    return ret;
}

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int tag, radix;
    scanf("%d%d", &tag, &radix);
    if (tag == 2)
        std::swap(str1, str2);
    d1 = x_to_d(str1, radix);
    int min_radix = findMinRadix(str2);
    long long max_radix;
    if (str2.size() == 1)
    {
        max_radix = d1;
        if (d1 >= 36)
        {
            printf("Impossible");
            return 0;
        }
    }
    else if (str2.size() == 2)
        max_radix = d1;
    else
        for (max_radix = 2; quick_pow(max_radix, str2.size() - 1) <= d1; ++max_radix);
    int ret = bin_search(min_radix, max_radix, str2);
    if (x_to_d(str2, ret) == d1)
        printf("%d", ret);
    else
        printf("Impossible");
    return 0;
}
