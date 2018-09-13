
// 最长公共子序列

#include <iostream>
#include <vector>
#include <string>

int main()
{
    for (std::string str1, str2; std::cin >> str1 >> str2; )
    {
        // dp[i][j]表示str1[0..i]与str2[0..j]的最长公共子序列
        std::vector<std::vector<int> > dp(str1.size(), std::vector<int>(str2.size(), 0));
        if (str1[0] == str2[0])
            dp[0][0] = 1;
        for (int i = 1; i < str2.size(); ++i)
        {
            if (str2[i] == str1[0])
                dp[0][i] = 1;
            else
                dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i < str1.size(); ++i)
        {
            if (str1[i] == str2[0])
                dp[i][0] = 1;
            else
                dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < str1.size(); ++i)
        {
            for (int j = 1; j < str2.size(); ++j)
            {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        std::cout << dp[str1.size() - 1][str2.size() - 1] << std::endl;
    }
    return 0;
}

