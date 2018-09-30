#include <cstdio>
#include <vector>
#include <queue>

struct Node
{
    int level;
    int no;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int> > tree(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int no, num;
        scanf("%d%d", &no, &num);
        for (int j = 0; j < num; ++j)
        {
            int child;
            scanf("%d", &child);
            tree[no].push_back(child);
        }
    }
    std::queue<Node> Q;
    Q.push(Node{0, 1});
    std::vector<int> mp;
    while (!Q.empty())
    {
        Node curr = Q.front();
        Q.pop();
        if (curr.level >= mp.size())
            mp.push_back(0);
        if (tree[curr.no].empty())
        {
            ++mp[curr.level];
            continue;
        }
        for (std::size_t i = 0; i < tree[curr.no].size(); ++i)
            Q.push(Node{curr.level + 1, tree[curr.no][i]});
    }
    for (int i = 0; i < mp.size(); ++i)
    {
        printf("%d", mp[i]);
        if (i != mp.size() - 1)
            printf(" ");
    }
    return 0;
}
