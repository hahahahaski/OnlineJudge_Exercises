#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::map<std::string, int> stu;
    std::vector<int> C(n), M(n), E(n);
    std::vector<double> A(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        std::string num;
        std::cin >> num;
        stu[num] = i;
        std::cin >> C[i] >> M[i] >> E[i];
        A[i] = (C[i] + M[i] + E[i]) * 1.0 / 3;
    }
    for (int i = 1; i <= m; ++i)
    {
        std::string str;
        std::cin >> str;
        if (stu.find(str) == stu.end())
        {
            std::cout << "N/A\n";
            continue;
        }
        int num = stu[str];
        int rank[4] = {1, 1, 1, 1}; // A C M E
        char ch[4] = {'A', 'C', 'M', 'E'};
        for (int i = 0; i < n; ++i)
            if (C[i] > C[num])
                ++rank[1];
        for (int i = 0; i < n; ++i)
            if (M[i] > M[num])
                ++rank[2];
        for (int i = 0; i < n; ++i)
            if (E[i] > E[num])
                ++rank[3];
        for (int i = 0; i < n; ++i)
            if (A[i] > A[num])
                ++rank[0];
        int max = n + 1;
        int flag = -1;
        for (int i = 0; i < 4; ++i)
        {
            if (rank[i] < max)
            {
                max = rank[i];
                flag = i;
            } 
        }
        std::cout << max << " " << ch[flag] << std::endl;
    }
    return 0;
}

