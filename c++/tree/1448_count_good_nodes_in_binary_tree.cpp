// tree: leetcode medium
/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes
with a value greater than X.

Return the number of good nodes in the binary tree.
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
    int count = 0;
    int goodNodes(TreeNode *root)
    {
        traverse(root, INT_MIN);
        return count;
    }

private:
    void traverse(TreeNode *node, int curr_max)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->val >= curr_max)
        {
            count++;
            curr_max = node->val;
        }
        traverse(node->left, curr_max);
        traverse(node->right, curr_max);
    }
};
// both time and space: O(n)