
// 数列极差问题

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    for (int N = 0; std::cin >> N && N != 0; )
    {
        std::vector<int> ivec;
        for (int i = 1; i <= N; ++i)
        {
            int temp = 0;
            std::cin >> temp;
            ivec.push_back(temp);
        }
        sort(ivec.begin(), ivec.end());
        // 贪心
        // 对于min，每次都选最大的两个数
        // 对于max，每次都选最小的两个数
        int minValue = ivec[N - 1];
        for (int i = N - 2; i >= 0; --i)
            minValue = minValue * ivec[i] + 1;
        for (int i = 1; i < N; ++i)
        {
            ivec[i] = ivec[i] * ivec[i - 1] + 1;
            for (int j = i + 1; j < N && ivec[j] < ivec[j - 1]; ++j)
                std::swap(ivec[j], ivec[j - 1]);
        }
        std::cout << ivec[N - 1] - minValue << std::endl;
    }
    return 0;
}

