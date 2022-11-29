// tree: leetcode medium (Blind 75 LeetCode Questions)
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool helper_validate(TreeNode *t)
    {
        if (t->left == nullptr && t->right == nullptr)
        {
            return true;
        }
        int value = t->val;
        if (t->left != nullptr)
        {
            if (t->left->val >= value)
            {
                break;
            }
            return helper_validate(t->left);
        }
        if (t->right != nullptr)
        {
            if (t->right->val <= value)
            {
                break;
            }
            return helper_validate(t->right);
        }
        return false;
    };

    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }
        return helper_validate(root);
    }
};