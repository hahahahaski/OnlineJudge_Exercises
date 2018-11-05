#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int num = 0;

struct TreeNode
{
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

TreeNode* revert(const std::vector<int> &post, const std::vector<int> &in)
{
    if (!post.empty())
    {
        TreeNode* root = new TreeNode(post.back());
        auto it = find(in.begin(), in.end(), post.back());
        std::vector<int> leftIn(in.begin(), it), rightIn(it + 1, in.end());
        int size = leftIn.size();
        std::vector<int> leftPost(post.begin(), post.begin() + size);
        std::vector<int> rightPost(post.begin() + size, post.end() - 1);
        root->left = revert(leftPost, leftIn);
        root->right = revert(rightPost, rightIn);
        return root;
    }
    return nullptr;
}

void LevelOrderTraversal(TreeNode* root)
{
    std::queue<TreeNode*> Q;
    int cnt = 1;
    if (root)
        Q.push(root);
    while (!Q.empty())
    {
        TreeNode* node = Q.front();
        Q.pop();
        std::cout << node->val;
        if (cnt < num)
            std::cout << " ";
        ++cnt;
        if (node->left)
            Q.push(node->left);
        if (node->right)
            Q.push(node->right);
    }
}

int main()
{
    std::cin >> num;
    std::vector<int> post(num), in(num);
    for (int i = 0; i < num; ++i)
        std::cin >> post[i];
    for (int i = 0; i < num; ++i)
        std::cin >> in[i];
    TreeNode* root = revert(post, in);    
    LevelOrderTraversal(root);
    return 0;
}

