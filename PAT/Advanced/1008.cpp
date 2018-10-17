#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> ivec(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> ivec[i];
    int sum = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ivec[i] > curr)
            sum += (ivec[i] - curr) * 6;
        else if (ivec[i] < curr)
            sum += (curr - ivec[i]) * 4;
        curr = ivec[i];
        sum += 5;
    }
    std::cout << sum;
    return 0;
}

