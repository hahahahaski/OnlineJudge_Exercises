#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>

int start[9];
int dest[9];
int dest_state;

int dir[9][4] = { {-1, -1, 1, 3},  
                  {-1, 0, 2, 4}, 
                  {-1, -1, 1, 5}, 
                  {-1, 0, 4, 6},
                  {1, 3, 5, 7}, 
                  {-1, 2, 4, 8}, 
                  {-1, -1, 3, 7}, 
                  {-1, 4, 6, 8}, 
                  {-1, -1, 5, 7} };

int pos[9];

int inversions(const int* arr)
{
    int ret = 0;
    for (std::size_t i = 0; i < 9; ++i)
    {
        if (arr[i] == 0)
            continue;
        for (std::size_t j = i + 1; j < 9; ++j)
        {
            if (arr[j] == 0)
                continue;
            if (arr[i] > arr[j])
                ++ret;
        }
    }
    return ret;
}

int Manhattan_distance(const int* arr)
{
    int ret = 0;
    for (std::size_t i = 0; i < 9; ++i)
        if (arr[i] != 0)
            ret += abs(i / 3 - pos[arr[i]] / 3) + abs(i % 3 - pos[arr[i]] % 3);
    return ret;
}

int Manhattan_distance(int curr_state)
{
    int ret = 0;
    for (int i = 8; i >= 0; --i)
    {
        int mod = curr_state % 10;
        if (mod != 0)
            ret += abs(i / 3 - pos[mod] / 3) + abs(i % 3 - pos[mod] % 3);
        curr_state /= 10;
    }
    return ret;
}

inline int arr_to_int(const int* arr)
{
    int ret = 0;
    for (std::size_t i = 0; i < 9; ++i)
        ret = ret * 10 + arr[i];
    return ret;     
}

bool found = false;

int DFS(int curr_state, int step, int bound)
{
    //printf("%d %d %d \n", curr_state, step, bound);
    
    int f = step + Manhattan_distance(curr_state);
    if (f > bound)
        return f;
    if (curr_state == dest_state)
    {
        found = true;
        return step;
    }
    int next[9];
    int pos = -1;
    for (int i = 8; i >= 0; --i)
    {
        next[i] = curr_state % 10;
        if (next[i] == 0)
            pos = i;
        curr_state /= 10;
    }
    int min = INT_MAX;
    for (std::size_t i = 0; i < 4; ++i)
    {
        int swap_pos = dir[pos][i];
        if (swap_pos != -1)
        {
            std::swap(next[pos], next[swap_pos]);
            int next_state = arr_to_int(next);
            int t = DFS(next_state, step + 1, bound);
            if (found)
                return t;
            if (t < min)
                min = t;
            std::swap(next[pos], next[swap_pos]);
        }
    }
    return min;
}

int IDA_star(int start_state)
{
    int bound = Manhattan_distance(start_state);
    while (1)
    {
        int t = DFS(start_state, 0, bound);
        if (found)
            return t;
        if (t == INT_MAX)
            return -1;
        bound = t;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (std::size_t i = 0; i < 9; ++i)
            scanf("%d", &start[i]);
        for (std::size_t i = 0; i < 9; ++i)
            scanf("%d", &dest[i]);
        int start_inversions = inversions(start);
        int goal_inversions = inversions(dest);
        if ((start_inversions & 1) != (goal_inversions & 1))
        {
            printf("-1\n");
            continue;
        }
        for (std::size_t i = 0; i < 9; ++i)
            pos[dest[i]] = i;
        dest_state = arr_to_int(dest);
        printf("%d\n", IDA_star(arr_to_int(start)));
    }
    return 0;
}

