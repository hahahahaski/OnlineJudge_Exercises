#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int n, k;

struct Task
{
    int t;
    int dur;
    bool operator < (const Task& other) const { return t < other.t; }
};

int s_to_i(const std::string& str)
{
    int h = (str[0] - '0') * 10 + str[1] - '0';
    int m = (str[3] - '0') * 10 + str[4] - '0';
    int s = (str[6] - '0') * 10 + str[7] - '0';
    return h * 3600 + m * 60 + s;
}

struct Service
{
    std::size_t no;
    int end;
    bool operator < (const Service& other) const { return end > other.end; }
};

int main()
{
    scanf("%d%d", &n, &k);
    std::vector<Task> vec;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        int val;
        std::cin >> str >> val;
        val = std::min(val, 60);
        vec.push_back({s_to_i(str), val * 60});
    }
    std::sort(vec.begin(), vec.end());

    //for (std::size_t i = 0; i < vec.size(); ++i)
    //    printf("%d %d\n", vec[i].t, vec[i].dur);

    std::priority_queue<Service> Q;
    std::size_t i = 0;
    for ( ; i < vec.size(); ++i)
    {
        if (vec[i].t <= 61200 && Q.size() < k)
        {
            if (vec[i].t < 28800)
                Q.push({i, 28800 + vec[i].dur});
            else
                Q.push({i, vec[i].t + vec[i].dur});
        }
        else
            break;
    }
    //printf("\n");
    std::vector<int> ans;
    while (!Q.empty())
    {
        Service curr = Q.top();
        Q.pop();
        //printf("%d %d %d\n", curr.no, curr.end, curr.end - vec[curr.no].t);
        int diff = curr.end - vec[curr.no].t - vec[curr.no].dur;
        ans.push_back(diff);
        if (i < vec.size() && vec[i].t <= 61200)
        {
            int val = std::max(curr.end, vec[i].t);
            Q.push({i, val + vec[i].dur});
            ++i;
        }
    }
    if (ans.empty())
    {
        printf("0.0\n");
        return 0;
    }
    int sum = std::accumulate(ans.begin(), ans.end(), 0.0);
    double min = 1.0 * sum / 60;
    //printf("%f\n", min);
    double avg = min / ans.size();
    printf("%.1f\n", avg);
    return 0;
}
