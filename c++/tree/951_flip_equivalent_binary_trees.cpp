// tree: leetcode medium
/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.
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
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return flip(root1, root2);
    }

private:
    bool flip(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == node2)
        {
            return true; // both nullptr
        }
        if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
        {
            return false;
        }

        return (flip(node1->left, node2->left) && flip(node1->right, node2->right)) ||
               (flip(node1->left, node2->right) && flip(node1->right, node2->left));
    }
};
// time: O(min lengths); space: O(min heights)