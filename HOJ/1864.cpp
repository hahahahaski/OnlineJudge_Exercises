#include <iostream>
#include <cmath>

unsigned long long cal(unsigned k)
{
    double ans = log10(1.0 / sqrt(5.0)) + k * log10((1 + sqrt(5.0)) / 2) + log10(1.0 - pow((1 - sqrt(5.0)) / (1 + sqrt(5.0)), k)) + 1.0;
    return (unsigned long long)ans;
}

int main()
{
    int f[31] = {0};
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 30; ++i)
        f[i] = f[i - 1] + f[i - 2];
    int N = 0;
    std::cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        unsigned int k = 0;
        std::cin >> k;
        if (k <= 30)
            std::cout << (int)(log10(f[k]) + 1.0) << std::endl; 
        else
            std::cout << cal(k) << std::endl;
    }
    return 0;
}

