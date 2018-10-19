#include <iostream>
#include <cstring>
#include <queue>

const int N = 1001;
bool map[N][N] = {false};
bool mark[N][N] = {false};
int n = 0, m = 0, k = 0;
bool vis[N] = {false};

void BFS(int v)
{
    std::queue<int> Q;
    Q.push(v);
    vis[v] = true;
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        for (int i = 1; i <= n; ++i)
            if (mark[curr][i] && !vis[i])
            {
                Q.push(i);
                vis[i] = true;
            }
    }
}

int main()
{
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = true;
    }
    for (int i = 1; i <= k; ++i)
    {
        int v = 0;
        std::cin >> v;
        memmove(mark, map, sizeof(map));
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; ++i)
            mark[i][v] = mark[v][i] = false;
        int num = 0;
        for (int v = 1; v <= n; ++v)
            if (!vis[v])
            {
                BFS(v);
                ++num;
            }
        num = num > 2 ? num - 2 : 0;
        std::cout << num << std::endl;
    }
    return 0;
}

