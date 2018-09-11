
// 回文素数

#include <iostream>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    int pal[110000] = {0};
    int palNum = 0;
    for (int i = 1; i <= 9; ++i)
        pal[palNum++] = i;
    for (int i = 1; i <= 9; ++i)
        pal[palNum++] = 11 * i;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            pal[palNum++] = 101 * i + 10 * j;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            pal[palNum++] = 1001 * i + 110 * j;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                pal[palNum++] = 10001 * i + 1010 * j + 100 * k;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                pal[palNum++] = 100001 * i + 10010 * j + 1100 * k;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                for (int l = 0; l <= 9; ++l)
                    pal[palNum++] = 1000001 * i + 100010 * j + 10100 * k + 1000 * l;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                for (int l = 0; l <= 9; ++l)
                    pal[palNum++] = 10000001 * i + 1000010 * j + 100100 * k + 11000 * l;
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k)
                for (int l = 0; l <= 9; ++l)
                    for (int m = 0; m <= 9; ++m)
                        pal[palNum++] = 100000001 * i + 10000010 * j + 1000100 * k + 101000 * l + 10000 * m;
    for (int i = 0; i < palNum && pal[i] <= b; ++i)
    {
        if (pal[i] >= a && isPrime(pal[i]))
            std::cout << pal[i] << std::endl;
    }
    return 0;
}

/*
 * #include <iostream>
#include <cstdio>
#include <vector>

// HOJ

bool isPal(int n)
{
    char number[11];
    sprintf(number, "%d", n);
    std::string str = number;
    for (std::string::size_type i = 0, j = str.size() - 1; i < j; ++i, --j)
        if (str[i] != str[j])
            return false;
    return true;
}


bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}


bool isPal(int n)
{
    int copy = n;
    int sum = 0;
    while (copy)
    {
        sum = sum * 10 + copy % 10;
        copy /= 10;
    }
    if (sum == n)
        return true;
    return false;
}

// 妥妥的超时
int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    for (int i = a; i <= b; ++i)
        if (isPal(i) && isPrime(i))
            std::cout << i << std::endl;
    return 0;
}
*/
/*
int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::vector<bool> isPrime(1000000001, true);
    std::vector<int> prime;
    isPrime[0] = isPrime[1] = false;
    // 普通筛法筛素数
    // O(nloglogn)
    // 照样超时
    
    for (std::vector<bool>::size_type i = 2; i <= b; ++i)
    {
        if (isPrime[i])
        {
            // 这儿j从i开始，而不是从2开始，可以小优化一下
            for (int j = i; j * i <= b; ++j)
                isPrime[j * i] = false;
        }
    }

    // 欧拉线性筛法求素数
    // O(n)
    for (std::vector<bool>::size_type i = 2; i <= b; ++i)
    {
        if (isPrime[i])
            prime.push_back(i);
        for (std::vector<int>::size_type j = 0; j < prime.size() && prime[j] * i < b; ++j)
        {
            isPrime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = a; i <= b; ++i)
        if (isPrime[i] && isPal(i))
            std::cout << i << std::endl;
    return 0;
}


// 妥妥的Memory Limit Exceed
#define MAXN 1000000001
bool flag[MAXN] = {false};
int prime[51000000] = {0}; 

int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    int cnt = 0;
    for (int i = 2; i <= b; ++i)
    {
        if (!flag[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i < b; ++j)
        {
            flag[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = a; i <= b; ++i)
        if (!flag[i] && isPal(i))
            std::cout << i << std::endl;
    return 0;
}
*/
