// tree: leetcode medium
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses
in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into
on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    int rob(TreeNode *root)
    {
        vector<int> results = helper(root);
        return max(results[0], results[1]); // [rob, not rob]
    }

private:
    vector<int> helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        int rob = node->val + left[1] + right[1];
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return {rob, not_rob};
    };
};
// time: O(n), space: O(n)