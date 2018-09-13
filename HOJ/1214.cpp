#include <iostream>
#include <string>

#define SIZE 55

bool isStd(std::string str)
{
    for (int i = 1; i < str.size(); ++i)
        if (str[i] == '1' && str[i - 1] == '1')
            return false;
    return true;
}

int main()
{
    unsigned long long fib[SIZE + 1] = {0};
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= SIZE; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    int N = 0;
    std::cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        std::string str;
        std::cin >> str;
        int pos = 0;
        // 这里很重要！
        if ((pos = str.find('1')) == std::string::npos)
        {
            std::cout << "0 in decimal, already in standard form" << std::endl;
            continue;
        }
        str = std::string(str, pos);
        unsigned int value = 0;
        for (int j = 0; j < str.size(); ++j)
            value += (str[j] - '0') * fib[str.size() - j];
        std::cout << value << " in decimal, ";
        if (isStd(str))
            std::cout << "already in standard form" << std::endl;
        else
        {
            std::cout << "whose standard form is ";
            while (!isStd(str))
            {
                for (int i = 1; i < str.size(); ++i)
                {
                    if (str[i] == '1' && str[i - 1] == '1')
                    {
                        str[i] = '0';
                        str[i - 1] = '0';
                        if (i == 1)
                            std::cout << "1";
                        else
                            str[i - 2] = '1';
                    }
                }
            }
            std::cout << str << std::endl;
        }
    }
    return 0;
}

