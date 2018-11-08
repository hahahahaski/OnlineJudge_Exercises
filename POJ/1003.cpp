#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define MAXN 501

// AC
// Dijkstr + DFS

int n = 0, m = 0;
int c1 = 0, c2 = 0;

struct Node
{
    int num; // ¶¥µãºÅ0..n-1
    int len;
    Node(int in = 0, int il = 0, int ic = 0) :
        num(in), len(il) {}
    bool operator < (const Node& n) const
    {
        if (len == n.len)
            return num < n.num;
        return len > n.len;
    }
};

void Dijkstra(int start, std::vector<int> & dis, const std::vector<std::vector<Node> > & map)
{
    dis[start] = 0;
    std::priority_queue<Node> Q;
    Q.push(Node(start, 0));
    while (!Q.empty())
    {
        Node curr = Q.top();
        Q.pop();
        for (int i = 0; i < map[curr.num].size(); ++i)
        {
            Node temp = map[curr.num][i];
            if (curr.len + temp.len < dis[temp.num])
            {
                dis[temp.num] = curr.len + temp.len;
                Q.push(Node(temp.num, dis[temp.num]));
            }
        }
    }
}

//bool vis[MAXN] = {false};
int minLen = 0;
int maxCnt = INT_MIN;
bool vis[MAXN][MAXN] = {false};
int roads = 0;

void DFS(int curr, int len, int cnt, const std::vector<int> & rt, const std::vector<std::vector<Node> > & map)
{
    if (len > minLen)
        return;
    if (curr == c2)
    {
        if (len == minLen)
        {
            ++roads;
            if (cnt > maxCnt)
                maxCnt = cnt;
        }
        return;
    }
    for (int i = 0; i < map[curr].size(); ++i)
    {
        if (!vis[curr][map[curr][i].num])
        {
            vis[curr][map[curr][i].num] = true;
            vis[map[curr][i].num][curr] = true;
            DFS(map[curr][i].num, len + map[curr][i].len, cnt + rt[map[curr][i].num], rt, map);
            vis[curr][map[curr][i].num] = false;
            vis[map[curr][i].num][curr] = false;
        }
    }
}

int main()
{
    std::cin >> n >> m >> c1 >> c2;
    std::vector<int> rt(n, 0);
    for (int i = 0; i < n; ++i)
        std::cin >> rt[i];
    std::vector<std::vector<Node> > map(n, std::vector<Node>());
    for (int i = 0; i < m; ++i)
    {
        int x = 0, y = 0, len = 0;
        std::cin >> x >> y >> len;
        map[x].push_back(Node(y, len));
        map[y].push_back(Node(x, len));
    }
    std::vector<int> dis(n, INT_MAX);
    Dijkstra(c1, dis, map);
    minLen = dis[c2];
    //std::cout << minLen << " ";
    //vis[c1] = true;
    DFS(c1, 0, rt[c1], rt, map);
    std::cout << roads << " " << maxCnt;
    return 0;
}

