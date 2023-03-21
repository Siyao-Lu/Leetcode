// tree: leetcode easy (Blind 75 LeetCode Questions)
/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(calcDepth(root->left), calcDepth(root->right)) + 1;
    }

private:
    int calcDepth(TreeNode *n)
    {
        int leftHeight = 0;
        int rightHeight = 0;
        if (n == nullptr)
            return 0;
        if (n->left == nullptr && n->right == nullptr)
            return 1;
        if (n->left != nullptr)
            leftHeight = calcDepth(n->left) + 1;
        if (n->right != nullptr)
            rightHeight = calcDepth(n->right) + 1;
        return max(leftHeight, rightHeight);
    }
};
// time: O(n)
// space: O(n) - n recursive calls, unbalanced tree