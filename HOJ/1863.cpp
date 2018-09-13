#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int testCase = 0;
    std::cin >> testCase;
    for (int i = 1; i <= testCase; ++i)
    {
        std::vector<int> ivec;
        for (int j = 1; j <= 10; ++j)
        {
            int temp = 0;
            std::cin >> temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size() - 1; ++j)
            std::cout << ivec[j] << " ";
        std::cout << ivec[ivec.size() - 1] << std::endl;
    }
    return 0;
}

