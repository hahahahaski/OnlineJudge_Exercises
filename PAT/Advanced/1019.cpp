#include <iostream>
#include <vector>

int main()
{
    int n = 0, b = 0;
    std::cin >> n >> b;
    std::vector<int> ivec;
    while (n >= b)
    {
        ivec.push_back(n % b);
        n /= b;
    }
    ivec.push_back(n);
    int i = 0, j = ivec.size() - 1;
    for ( ; i <= j && ivec[i] == ivec[j]; ++i, --j);
    if (i <= j)
        std::cout << "No\n";
    else
        std::cout << "Yes\n";
    for (i = ivec.size() - 1; i >= 1; --i)
        std::cout << ivec[i] << " ";
    std::cout << ivec[0];
    return 0;
}

