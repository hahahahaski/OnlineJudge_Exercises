#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

struct Node
{
    int v;
    int val; // time or dist
    bool operator < (const Node& other) const { return val > other.val; }
};

int cmax, n, sp, m; 

int min_len;

int Dijkstra(const std::vector<std::vector<Node> >& map, int s, int t)
{
    std::vector<int> dist(n + 1, INT_MAX);
    std::priority_queue<Node> Q;
    dist[s] = 0;
    Q.push(Node{s, 0});
    while (!Q.empty())
    {
        Node curr = Q.top();
        Q.pop();
        for (std::size_t i = 0; i < map[curr.v].size(); ++i)
        {
            int v = map[curr.v][i].v;
            if (curr.val + map[curr.v][i].val < dist[v])
            {
                dist[v] = curr.val + map[curr.v][i].val;
                Q.push(Node{v, dist[v]});
            }
        }
    }
    return dist[t];
}

bool vis[505] = {false};
int path[505];
int min_bike = INT_MAX;
int back_bike;
std::vector<int> ans;

void dfs(int curr, int dest, int len, int cnt, const std::vector<std::vector<Node> >& map, 
        const std::vector<int>& ivec)
{
    if (len > min_len)
        return;
    if (curr == dest && len == min_len)
    {
        int curr_bike = 0;
        int bike = 0;
        for (int i = 0; i < cnt; ++i)
        {
            if (ivec[path[i]] >= cmax)
                curr_bike += ivec[path[i]] - cmax;
            else if (curr_bike >= cmax - ivec[path[i]])
                curr_bike -= cmax - ivec[path[i]];
            else
            {
                bike += cmax - ivec[path[i]] - curr_bike;
                curr_bike = 0;
            }
        }
        //printf("bike = %d back_bike = %d\n", bike, curr_bike);
        if (bike < min_bike || (bike == min_bike && curr_bike < back_bike))
        {
            min_bike = bike;
            back_bike = curr_bike;
            ans.clear();
            for (int i = 0; i < cnt; ++i)
                ans.push_back(path[i]);
        }
        return;
    }
    for (std::size_t i = 0; i < map[curr].size(); ++i)
    {
        if (!vis[map[curr][i].v])
        {
            vis[map[curr][i].v] = true;
            path[cnt] = map[curr][i].v;
            dfs(map[curr][i].v, dest, len + map[curr][i].val, cnt + 1, map, ivec);
            vis[map[curr][i].v] = false;
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    cmax /= 2;
    std::vector<int> ivec(n + 1);
    for (std::size_t i = 1; i <= n; ++i)
        scanf("%d", &ivec[i]);
    std::vector<std::vector<Node> > map(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, t;
        scanf("%d%d%d", &v1, &v2, &t);
        map[v1].push_back(Node{v2, t});
        map[v2].push_back(Node{v1, t});
    }
    min_len = Dijkstra(map, 0, sp);
    //printf("%d", min_len);
    
    dfs(0, sp, 0, 0, map, ivec);
    printf("%d 0", min_bike);
    for (std::size_t i = 0; i < ans.size(); ++i)
        printf("->%d", ans[i]);
    printf(" %d", back_bike);
        
    return 0;
}
