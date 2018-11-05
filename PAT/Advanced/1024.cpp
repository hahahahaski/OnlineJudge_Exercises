#include <iostream>
#include <cstdio>
#include <string>

/*
int main()
{
    long long n = 0, k = 0;
    std::cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        long long copy = n;
        long long num = 0;
        while (copy)
        {
            num = num * 10 + copy % 10;
            copy /= 10;
        }
        if (num == n)
        {
            std::cout << n << std::endl << i;
            return 0;
        }
        n = n + num;
    }
    std::cout << n << std::endl << k;
    return 0;
}
    */

/*
bool isPal(std::string str)
{
    int i = 0, j = str.size() - 1;
    for ( ; i <= j && str[i] == str[j]; ++i, --j);
    if (i <= j)
        return false;
    return true;
}

int main()
{
    int n = 0, k = 0;
    std::cin >> n >> k;
    char ch[15];
    sprintf(ch, "%d", n);
    std::string str = ch;
    if (isPal(str))
    {
        std::cout << str << std::endl << 0;
        return 0;
    }
    for (int i = 1; i <= k; ++i)
    {
        std::string reverse(str.rbegin(), str.rend());
        std::string sum;
        int mod = 0;
        for (int j = str.size() - 1; j >= 0; --j)
        {
            sum += (str[j] + reverse[j] - 2 * '0' + mod) % 10 + '0';
            mod = (str[j] + reverse[j] - 2 * '0' + mod) / 10;
        }
        if (mod)
            sum += mod + '0';
        str = std::string(sum.rbegin(), sum.rend());
        if (isPal(str))
        {
            std::cout << str << std::endl << i;
            return 0;
        }
    }
    std::cout << str << std::endl << k;
    return 0;
}
*/


int main()
{
    std::string str;
    int k = 0;
    std::cin >> str >> k;
    int cnt = 0;
    for ( ; cnt < k; ++cnt)
    {
        std::string reverse = std::string(str.rbegin(), str.rend());
        if (reverse == str)
            break;
        else
        {
            std::string sum;
            int mod = 0;
            for (int j = str.size() - 1; j >= 0; --j)
            {
                sum.push_back((str[j] + reverse[j] - 2 * '0' + mod) % 10 + '0');
                mod = (str[j] + reverse[j] - 2 * '0' + mod) / 10;
            }
            if (mod)
                sum.push_back(mod + '0');
            str = std::string(sum.rbegin(), sum.rend());
        }
    }
    std::cout << str << std::endl << cnt << std::endl;
}

