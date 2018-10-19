#include <iostream>
#include <string>
#include <algorithm>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int d_to_x(int n, int radix)
{
    int ans = 0;
    while (n)
    {
        ans = ans * radix + n % radix;
        n /= radix;
    }
    return ans;
}

int main()
{
    for (int n = 0, radix = 0; std::cin >> n && n >= 0; )
    {
        std::cin >> radix;
        if (!isPrime(n))
        {
            std::cout << "No" << std::endl;
            continue;
        }
        if (isPrime(d_to_x(n, radix)))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}

