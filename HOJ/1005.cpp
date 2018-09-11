#include <iostream>
#include <vector>
#include <climits>

int main()
{
    for (int n = 0, ik = 0, cnt = 1; std::cin >> n >> ik && n != 0 && ik != 0; ++cnt)
    {
        std::vector<int> ivec;
        for (int i = 1; i <= n; ++i)
        {
            int temp = 0;
            std::cin >> temp;
            ivec.push_back(temp);
        }
        // distance[i][j]表示在ivec[i..j]之间选择一个数的最大收益
        // 0 =< i < j <= n - 1
        // 经判断，选择中位数时候，收益最大
        int distance[201][201] = {0};
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                distance[i][j] = distance[i][j - 1] + ivec[j] - ivec[(i + j) / 2];
        // dp[i][j]表示在ivec[0..i]中选择j个数的最大收益
        int dp[201][31] = {0};
        for (int i = 0; i < n; ++i)
            dp[i][1] = distance[0][i];
        for (int j = 2; j <= ik; ++j)
        {
            for (int i = j - 1; i < n; ++i)
            {
                int currValue = INT_MAX;
                for (int k = 0; k < i; ++k)
                {
                    if (dp[k][j - 1] + distance[k + 1][i] < currValue)
                        currValue = dp[k][j - 1] + distance[k + 1][i];
                }
                dp[i][j] = currValue;
            }
        }
        std::cout << "Chain " << cnt << std::endl;
        std::cout << "Total distance sum = " << dp[n - 1][ik] << std::endl << std::endl;
    }
    return 0;
}

