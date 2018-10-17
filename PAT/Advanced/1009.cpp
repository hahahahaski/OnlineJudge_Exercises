#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

#define EXP 1e-6

struct Node
{
    int expon;
    float coef;
    Node(int ie = 0, float ic = 0.0f) : expon(ie), coef(ic) {}
};

std::vector<Node> add(const std::vector<Node>& vec1, const std::vector<Node>& vec2)
{
    std::vector<Node> vec;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i].expon > vec2[j].expon)
            vec.push_back(vec1[i++]);
        else if (vec2[j].expon > vec1[i].expon)
            vec.push_back(vec2[j++]);
        else
        {
            float sum = vec1[i].coef + vec2[j].coef;
            if (fabs(sum) > EXP)
                vec.push_back(Node(vec1[i].expon, sum));
            ++i, ++j;
        }
    }
    while (i < vec1.size())
        vec.push_back(vec1[i++]);
    while (j < vec2.size())
        vec.push_back(vec2[j++]);
    return vec;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<Node> vec1(n);
    for (int i = 0; i < n; ++i)
        std::cin >> vec1[i].expon >> vec1[i].coef;
    std::cin >> n;
    std::vector<Node> vec2(n);
    for (int i = 0; i < n; ++i)
        std::cin >> vec2[i].expon >> vec2[i].coef;
    std::vector<Node> ans;
    for (int i = 0; i < vec1.size(); ++i)
    {
        std::vector<Node> temp;
        for (int j = 0; j < vec2.size(); ++j)
            temp.push_back(Node(vec1[i].expon + vec2[j].expon, vec1[i].coef * vec2[j].coef));
        ans = add(ans, temp);
    }
    std::cout << ans.size();
    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << " " << ans[i].expon << " ";
        printf("%.1f", ans[i].coef);
    }
    return 0;
}

