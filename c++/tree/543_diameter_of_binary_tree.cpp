// tree: leetcode easy
/*
Given the root of a binary tree, return the length of the diameter of the tree.
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
    int maxLength = 0;
    int find(TreeNode *node)
    { // longest path has to be from two leaf => max depth from left + max depth from right
        if (node == nullptr)
        {
            return 0;
        }
        int left = find(node->left);
        int right = find(node->right);
        maxLength = max(left + right, maxLength);
        return (max(left, right) + 1);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        find(root);
        return maxLength;
    }
};
// space:O(n), time: O(n)
