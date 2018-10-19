#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

struct Game
{
    char tag;
    double odd;
    bool operator < (const Game &g) const { return odd < g.odd; }
};

int main()
{
    std::vector<Game> dvec(9);
    char map[] = { 'L', 'W', 'T',};
    for (int i = 0; i <= 8; ++i)
    {
        std::cin >> dvec[i].odd;
        dvec[i].tag = map[(i + 1) % 3];
    }
    std::vector<Game>::iterator it = dvec.begin(); 
    sort(it, it + 3);
    sort(it + 3, it + 6);
    sort(it + 6, it + 9);
    std::cout << dvec[2].tag << " " << dvec[5].tag << " " << dvec[8].tag << " "; 
    double res = (dvec[2].odd * dvec[5].odd * dvec[8].odd * 0.65 - 1) * 2;
    printf("%.2f", res);
    return 0;
}

