// tree: leetcode easy
/*
Given a binary tree, find its minimum depth.
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
    int minDepth(TreeNode *root)
    {
        // base case
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int minD = INT_MAX;
        if (root->left != nullptr)
        {
            minD = min(minDepth(root->left), minD);
        }
        if (root->right != nullptr)
        {
            minD = min(minDepth(root->right), minD);
        }
        return minD + 1;
    }
};
// time: O(n), space; O(logn)