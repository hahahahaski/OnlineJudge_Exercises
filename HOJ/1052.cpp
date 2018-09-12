#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> 
#include <cmath>

// 贪心
// 区间选点问题

#define EXP 1E-6

// 求以p点为圆心d为半径的圆与x轴的两个交点坐标
// first为左交点横坐标，second为右交点横坐标
std::pair<double, double> getCoor(std::pair<double, double>& p, int d)
{
    double temp = sqrt(double(d * d) - p.second * p.second);
    return std::make_pair(p.first - temp, p.first + temp);
}

bool compare(const std::pair<double, double> & c1, const std::pair<double, double> & c2)
{
    if (fabs(c1.second - c2.second) < EXP)
        return c1.first > c2.first;
    return c1.second < c2.second;
}

int main()
{
    for (int n = 0, d = 0, test = 1; std::cin >> n >> d && (n != 0 || d != 0); ++test)
    {
        std::vector<std::pair<double, double> > ivec;
        double coorX = 0.0, coorY = 0.0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> coorX >> coorY;
            ivec.push_back(std::make_pair(coorX, coorY));
        }
        std::vector<std::pair<double, double> > coor;
        bool bFlag = true;
        std::cout << "Case " << test << ": ";
        for (int i = 0; i < ivec.size(); ++i)
        {
            if (fabs(ivec[i].second) > d)
            {
                std::cout << "-1" << std::endl;
                bFlag = false;
                break;
            }
            else
                coor.push_back(getCoor(ivec[i], d)); 
        }
        if (bFlag == false)
            continue;
        sort(coor.begin(), coor.end(), compare);
        int cnt = 1;
        double curr = coor[0].second;
        for (int i = 1; i < coor.size(); ++i)
        {
            if (curr < coor[i].first)
            {
                curr = coor[i].second;
                ++cnt;
            }
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}

