// tree: leetcode easy
/*
Given a binary tree, determine if it is height-balanced
*/
#include <algorithm>
#include <cmath>
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
    bool helper(TreeNode *node, int &height)
    {
        if (node == nullptr)
        {
            height = -1;
            return true;
        }
        int left;
        int right;
        if (helper(node->left, left) && helper(node->right, right) && (abs(left - right) <= 1))
        {
            height = max(left, right) + 1;
            return true;
        }
        return false;
    };
    bool isBalanced(TreeNode *root)
    {
        int height;
        return helper(root, height);
    }
};
// time: O(n), space: O(n)