#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(const std::pair<int, int> & p1, const std::pair<int, int> & p2)
{
    return p1.first < p2.first;
}

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<std::pair<int, int> > farmers;
    for (int i = 1; i <= M; ++i)
    {
        int price = 0, amount = 0;
        std::cin >> price >> amount;
        std::pair<int, int> temp(price, amount);
        farmers.push_back(temp);
    }
    sort(farmers.begin(), farmers.end(), compare);
    int totalPrice = 0;
    std::vector<int>::size_type i = 0;
    for ( ; i < farmers.size() && N >= farmers[i].second; ++i)
    {
        totalPrice += farmers[i].first * farmers[i].second;
        N -= farmers[i].second;
    }
    totalPrice += farmers[i].first * N;
    std::cout << totalPrice << std::endl;
    return 0;
}

