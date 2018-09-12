#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>

long long dp[100][100] = {0};
int cost[100][100] = {0};
int ans[100][100] = {0};
int frequence[100] = {0};
std::string strKey, strLetter;

void dfs(int K, int L)
{
    if (K == 0)
        return;
    dfs(K - 1, L - ans[K][L]);
    std::cout << strKey[K - 1] << ": ";
    for (int i = L - ans[K][L]; i < L; ++i)
        std::cout << strLetter[i];
    std::cout << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int cnt = 1; cnt <= T; ++cnt)
    {
        int K = 0, L = 0;
        memset(dp, 0x7f, sizeof(dp));
        memset(cost, 0, sizeof(cost));
        memset(ans, 0, sizeof(ans));
        std::cin >> K >> L;
        std::cin >> strKey >> strLetter;
        
        for (int i = 1; i <= L; ++i)
        {
            int temp = 0;
            std::cin >> temp;
            frequence[i] = temp;
        }
        for (int i = 1; i <= L; ++i)
        {
            for (int j = i; j <= L; ++j)
                cost[i][j] = cost[i][j - 1] + (j - i + 1) * frequence[j];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= K; ++i)
        {
            for (int j = i; j <= L; ++j)
            {
                for (int k = 1; k <= j - i + 1; ++k)
                {   
                    if (dp[i - 1][j - k] + cost[j - k + 1][j] <= dp[i][j])
                    {
                        dp[i][j] = dp[i - 1][j - k] + cost[j - k + 1][j];
                        ans[i][j] = k;
                    }
                }
            }
        }
        std::cout << "Keypad #" << cnt << ":" << std::endl;
        dfs(K, L);
        std::cout << std::endl;
    }
    return 0;
}

