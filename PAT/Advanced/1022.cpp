#include <cstdio>
#include <iostream>
#include <map>
#include <set>

int main()
{
    int n;
    scanf("%d", &n);
    std::map<std::string, std::set<std::string> > title_mp;
    std::map<std::string, std::set<std::string> > author_mp;
    std::map<std::string, std::set<std::string> > key_mp;
    std::map<std::string, std::set<std::string> > pub_mp;
    std::map<std::string, std::set<std::string> > year_mp;
    for (int i = 0; i < n; ++i)
    {
        std::string id;
        std::cin >> id;
        std::string str;
        std::cin.get();
        std::getline(std::cin, str);
        title_mp[str].insert(id);
        std::getline(std::cin, str);
        author_mp[str].insert(id);
        std::getline(std::cin, str);
        std::size_t beg = 0;
        for (std::size_t i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
                key_mp[str.substr(beg, i - beg)].insert(id);
                beg = i + 1;
            }
        }
        key_mp[str.substr(beg)].insert(id);
        std::getline(std::cin, str);
        pub_mp[str].insert(id);
        std::getline(std::cin, str);
        year_mp[str].insert(id);
    }
    int m;
    scanf("%d", &m);
    std::cin.get();
    for (int i = 0; i < m; ++i)
    {
        std::string str1;
        std::getline(std::cin, str1);
        int type = str1[0] - '0';
        std::string str = str1.substr(3);
        std::cout << str1 << "\n";
        switch (type)
        {
            case 1:
                {
                    auto it = title_mp.find(str);
                    if (it == title_mp.end())
                        printf("Not Found\n");
                    else
                    {
                        for (auto& id: it->second)
                            std::cout << id << std::endl;
                    }
                }
                break;
            case 2:
                {
                    auto it = author_mp.find(str);
                    if (it == author_mp.end())
                        printf("Not Found\n");
                    else
                    {
                        for (auto& id: it->second)
                            std::cout << id << std::endl;
                    }
                }
                break;
            case 3:
                {
                    auto it = key_mp.find(str);
                    if (it == key_mp.end())
                        printf("Not Found\n");
                    else
                    {
                        for (auto& id: it->second)
                            std::cout << id << std::endl;
                    }
                }
                break;
            case 4:
                {
                    auto it = pub_mp.find(str);
                    if (it == pub_mp.end())
                        printf("Not Found\n");
                    else
                    {
                        for (auto& id: it->second)
                            std::cout << id << std::endl;
                    }
                }
                break;
            case 5:
                {
                    auto it = year_mp.find(str);
                    if (it == year_mp.end())
                        printf("Not Found\n");
                    else
                    {
                        for (auto& id: it->second)
                            std::cout << id << std::endl;
                    }
                }
                break;
        }
    }
    return 0;
}
