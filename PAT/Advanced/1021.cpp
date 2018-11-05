#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

const int MAXN = 10002;

bool vis[MAXN] = {false};

void BFS(int v, const std::vector<std::vector<int> > & map)
{
    std::queue<int> Q;
    Q.push(v);
    vis[v] = true;
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        for (int i = 0; i < map[curr].size(); ++i)
            if (!vis[map[curr][i]])
            {
                Q.push(map[curr][i]);
                vis[map[curr][i]] = true;
            }
    }
}

int getDepth(int root, const std::vector<std::vector<int> > & map)
{
    int height = 0;
    for (int i = 0; i < map[root].size(); ++i)
    {
        if (!vis[map[root][i]])
        {
            vis[map[root][i]] = true;
            int h = getDepth(map[root][i], map);
            if (h > height)
                height = h;
        }
    }
    return height + 1;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int> > map(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;
        map[v1].push_back(v2);
        map[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            BFS(i, map);
            ++cnt;
        }
    if (cnt > 1)
    {
        std::cout << "Error: " << cnt << " components";
        return 0;
    }
    int height = -1;
    std::vector<int> res;
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        int h = getDepth(i, map);
        if (h > height)
        {
            height = h;
            res.clear();
            res.push_back(i);
        }
        else if (h == height)
            res.push_back(i);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i)
        std::cout << res[i] << std::endl;
    return 0; 
}

