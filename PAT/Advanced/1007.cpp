#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> ivec(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> ivec[i];
    int maxValue = INT_MIN;
    int start = 0, end = -1;
    int curr = 0, currStart = 0;
    for (int i = 0; i < n; ++i)
    {
        curr += ivec[i];
        if (curr > maxValue)
        {
            maxValue = curr;
            start = currStart;
            end = i;
        }
        if (curr < 0)
        {
            curr = 0;
            currStart = i + 1;
        }
    }
    if (maxValue < 0)
        std::cout << "0 " << ivec[0] << " " << ivec[n - 1];
    else
        std::cout << maxValue << " " << ivec[start] << " " << ivec[end];
    return 0;
}

