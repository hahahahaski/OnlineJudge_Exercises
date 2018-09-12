#include <iostream>
#include <vector>

int main()
{
    for (int R = 0; std::cin >> R; )
    {
        std::vector<std::vector<int> > triangle;
        std::vector<std::vector<int> > dp;
        for (int i = 1; i <= R; ++i)
        {
            std::vector<int> ivec;
            std::vector<int> dpTemp;
            for (int j = 1; j <= i; ++j)
            {
                int temp = 0;
                std::cin >> temp;
                ivec.push_back(temp);
                dpTemp.push_back(0);
            }
            triangle.push_back(ivec);
            dp.push_back(dpTemp);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < R; ++i)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        for (int i = 2; i < R; ++i)
        {
            for (int j = 1; j < i; ++j)
                dp[i][j] = dp[i - 1][j] > dp[i - 1][j - 1]
                         ? dp[i - 1][j] + triangle[i][j]
                         : dp[i - 1][j - 1] + triangle[i][j];
        }
        int maxValue = dp[R - 1][0];
        for (int i = 1; i < R; ++i)
            if (dp[R - 1][i] > maxValue)
                maxValue = dp[R -1][i];
        std::cout << maxValue << std::endl;
    }
    return 0;
}

