// tree: leetcode easy (Blind 75 LeetCode Questions)
/*
Given the roots of two binary trees root and subRoot,
return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
The tree tree could also be considered as a subtree of itself.
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
    TreeNode *helper(TreeNode *r, TreeNode *subr)
    {
        TreeNode *potential = nullptr;
        while (r != nullptr)
        {
            if (r != nullptr && r->val == subr->val)
                return r;
        }
        return potential;
    };

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        TreeNode *potential = nullptr;
        while (root != nullptr)
        {
        }
        if (potential == nullptr)
            return false;
        else
            return true;
    }
};