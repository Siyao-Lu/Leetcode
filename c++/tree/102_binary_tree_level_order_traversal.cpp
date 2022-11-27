// tree: leetcode medium (Blind 75 LeetCode Questions)
/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).
*/

#include <algorithm>
#include <vector>
#include <map>
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
    map<int, vector<int>> order;
    void traverse_helper(TreeNode *node, int level)
    {
        order[level].push_back(node->val);
        if (node->left != nullptr)
        {
            traverse_helper(node->left, level + 1);
        }
        if (node->right != nullptr)
        {
            traverse_helper(node->right, level + 1);
        }
    };

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> output;
        if (root == nullptr)
        {
            return {};
        }
        traverse_helper(root, 0);
        for (int i = 0; i < order.size(); i++)
        {
            output.push_back(order[i]);
        }
        return output;
    }
};
// time: O(n), space can be improved with queue => O(n)