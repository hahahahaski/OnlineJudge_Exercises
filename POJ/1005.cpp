#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string word[10] = {"zero", "one", "two", "three", "four",
                            "five", "six", "seven", "eight", "nine"};
    std::string str;
    std::cin >> str;
    int num = 0;
    for (int i = 0; i < str.size(); ++i)
        num += str[i] - '0';
    std::vector<int> ivec;
    while (num)
    {
        ivec.push_back(num % 10);
        num /= 10;
    }
    if (ivec.empty())
        std::cout << "zero";
    else
    {
        for (int i = ivec.size() - 1; i >= 1; --i)
            std::cout << word[ivec[i]] << " ";
        std::cout << word[ivec[0]];
    }
    return 0;
}   

