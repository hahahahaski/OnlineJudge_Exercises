#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person
{
    std::string name;
    std::string in;
    std::string out;
};

bool cmp1(const Person& p1, const Person& p2)
{
    return p1.in < p2.in;
}

bool cmp2(const Person& p1, const Person& p2)
{
    return p1.out < p2.out;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<Person> vec(n);
    for (int i = 0; i < n; ++i)
        std::cin >> vec[i].name >> vec[i].in >> vec[i].out;
    sort(vec.begin(), vec.end(), cmp1);
    std::cout << vec[0].name << " ";
    sort(vec.begin(), vec.end(), cmp2);
    std::cout << vec[n - 1].name;
    return 0;
}

