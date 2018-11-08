#include <iostream>
#include <map>
#include <string>
#include <vector>

int cnt[101] = {0};
int depth = 0;

void dfs(int level, std::string str, std::map<std::string, std::vector<std::string> > & tree)
{
    depth = level > depth ? level : depth;
    if (tree[str].empty())
    {
        ++cnt[level];
        return;
    }
    for (int i = 0; i < tree[str].size(); ++i)
    {
        dfs(level + 1, tree[str][i], tree);
    }
}

int main()
{
    int num = 0;
    std::cin >> num >> num;
    std::map<std::string, std::vector<std::string> > tree;
    for (int i = 1; i <= num; ++i)
    {
        std::string str;
        std::cin >> str;
        int n = 0;
        std::cin >> n;
        for (int j = 1; j <= n; ++j)
        {
            std::string child;
            std::cin >> child;
            tree[str].push_back(child); 
        }
    }
    dfs(1, "01", tree);
    std::cout << cnt[1];
    for (int i = 2; i <= depth; ++i)
        std::cout << " " << cnt[i];
    return 0;
}

