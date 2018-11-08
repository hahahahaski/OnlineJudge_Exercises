#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    int cnt[10] = {0};
    for (int i = 0; i < str.size(); ++i)
        ++cnt[str[i] - '0'];
    std::string doubled;
    int mod = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        doubled += ((str[i] - '0') * 2 + mod) % 10 + '0';
        mod = ((str[i] - '0') * 2 + mod) / 10;
    }
    if (mod)
        doubled += mod + '0';
    doubled = std::string(doubled.rbegin(), doubled.rend());
    for (int i = 0; i < doubled.size(); ++i)
        if (--cnt[doubled[i] - '0'] < 0)
        {
            std::cout << "No\n" << doubled;
            return 0;
        }
    std::cout << "Yes\n" << doubled;
    return 0;
}

