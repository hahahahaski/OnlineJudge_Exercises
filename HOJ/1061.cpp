#include <iostream>

int main()
{
    // зЂвтвЊвдULL
    unsigned long long dp[21][21] = {0};
    for (int i = 1; i <= 20; ++i)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
        for (int j = 2; j < i; ++j)
            dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
    }
    for (int n = 0, k = 0; std::cin >> n >> k; )
        std::cout << dp[n][k] << std::endl;
    return 0;
}

