#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int n;

bool vis[10005] = {false};

void dfs(const std::vector<std::vector<int> >& tree, int curr)
{
    for (std::size_t i = 0; i < tree[curr].size(); ++i)
    {
        if (!vis[tree[curr][i]])
        {
            vis[tree[curr][i]] = true;
            dfs(tree, tree[curr][i]);
        }
    }
}

int depth(const std::vector<std::vector<int> >& tree, int curr)
{
    int d = 0;
    for (std::size_t i = 0; i < tree[curr].size(); ++i)
    {
        if (!vis[tree[curr][i]])
        {
            vis[tree[curr][i]] = true;
            d = std::max(d, depth(tree, tree[curr][i]));
        }
    }
    return d + 1;
}

int main()
{
    scanf("%d", &n);
    std::vector<std::vector<int> > tree(n + 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(tree, i);
            ++cnt;
        }
    }
    if (cnt > 1)
    {
        printf("Error: %d components", cnt);
        return 0;
    }
    std::vector<int> ivec(n + 1);
    int max_depth = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        ivec[i] = depth(tree, i);
        max_depth = std::max(max_depth, ivec[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ivec[i] == max_depth)
            printf("%d\n", i);
    }
}
