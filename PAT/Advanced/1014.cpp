#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

int n, m, k, q;

struct Service
{
    int end;
    std::size_t cus_no;
    std::size_t win_no;
    bool operator < (const Service& other) const 
    {
        if (end == other.end)
            return win_no > other.win_no;
        return end > other.end; 
    }
};

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    std::vector<int> vec(k + 1);
    for (std::size_t i = 1; i < vec.size(); ++i)
        scanf("%d", &vec[i]);
    std::vector<std::queue<std::size_t> > win(n);
    std::priority_queue<Service> Q;
    std::size_t i = 1;
    for ( ; i < vec.size() && i <= n; ++i)
    {
        Q.push( {480 + vec[i], i, i - 1} );
    }
    for (std::size_t j = 0; i < vec.size() && i <= n * m; ++i)
    {
        win[j].push(i);
        ++j;
        if (j == n)
            j = 0;
    }
    std::vector<int> ans(k + 1, -1);
    while (!Q.empty())
    {
        Service curr = Q.top();
        Q.pop();

        //printf("%d %d %02d:%02d\n", curr.cus_no, curr.win_no, curr.end / 60, curr.end % 60);

        ans[curr.cus_no] = curr.end;
        if (!win[curr.win_no].empty())
        {
            std::size_t cus_no = win[curr.win_no].front();
            win[curr.win_no].pop();
            if (curr.end < 1020)
            {
                Q.push( {curr.end + vec[cus_no], cus_no, curr.win_no} );
                if (i < vec.size())
                {
                    win[curr.win_no].push(i);
                    ++i;
                }
            }
        }
    }
    for (int j = 0; j < q; ++j)
    {
        int query;
        scanf("%d", &query);
        if (ans[query] == -1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", ans[query] / 60, ans[query] % 60);
    }
    return 0;
}
