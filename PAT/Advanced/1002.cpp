#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

const int EXP = 1e-6;

struct Node
{
    int expon;
    float coef;
    Node(int ie = 0, float fc = 0.0f) : expon(ie), coef(fc) {}
};

int main()
{
    int k = 0;
    std::cin >> k;
    std::vector<Node> vec1(k);
    for (int i = 0; i < k; ++i)
        std::cin >> vec1[i].expon >> vec1[i].coef;
    std::cin >> k;
    std::vector<Node> vec2(k);
    for (int i = 0; i < k; ++i)
        std::cin >> vec2[i].expon >> vec2[i].coef;
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
    std::cout << vec.size();
    for (i = 0; i < vec.size(); ++i)
    {
        std::cout << " " << vec[i].expon << " ";
        printf("%.1f", vec[i].coef);
    }
    return 0;
}

