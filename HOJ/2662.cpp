#include <iostream>
#include <cstring>

// 状态压缩DP
// 这题很难
// 大神的AC代码
// 

long long n = 0, m = 0, k = 0;
// dp[i][j][k]放置完第i行共用了j个棋子，第i行的状态为x时的方法数
long long dp[82][22][1 << 9];
long long ans;
// mark标记每一行的状态
long long mark[1 << 9], len;

long long num(long long x)
{
    long long sum = 0;
    while (x)
    {
        if (x & 1)
            ++sum;
        x >>= 1;
    }
    return sum;
}

bool judge(long long x)
{
    if (x & (x << 1))
        return false;
    return true;
}

int main()
{
    while (std::cin >> n >> m >> k)
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(mark, 0, sizeof(mark));
        len = 0;
        long long tepp = n > m ? n : m;
        m = n > m ? m : n; // m为小的数
        n = tepp;
        // 初始化第一行的放置方法数
        // 剔除某一行中的不合法放置状态
        for (long long i = 0; i < (1 << m); ++i)
        {
            // 若i状态没有相邻的棋子放在一起
            if (judge(i))
            {
                dp[1][num(i)][len] = 1; // 第一行状态为i时，用了num(i)个棋子的方法数
                mark[len++] = i; // 标记状态
            }
        }
        // 第2行到第n行
        for (long long i = 2; i <= n; ++i)
        {
            // 对于放0..k个棋子
            for (long long j = 0; j <= k; ++j)
            {
                // 枚举第i行0..len - 1个状态
                for (long long x = 0; x < len; ++x)
                {
                    // 枚举第i - 1行0..len - 1个状态 
                    for (long long y = 0; y < len; ++y)
                    {
                        // 第i行状态x中1的个数
                        long long tmp = num(mark[x]);
                        // 若上下两行没相邻的棋子
                        // 且当前的棋子数目大于此行当前状态所用的棋子数目
                        if ( ((mark[x] & mark[y]) == 0) && j >= tmp)
                            dp[i][j][x] += dp[i - 1][j - tmp][y]; // 施法数可相加
                            // 到当前行共用了j个棋子，当前用了tmp个棋子，状态为x；
                            // 到上一行共用了j - tmp个棋子，状态为y
                    }
                }
            }
        }
        // 枚举状态相加
        for (long long i = 0; i < len; ++i)
            ans += dp[n][k][i];
        std::cout << ans << std::endl;
    }
    return 0;
}

