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
    bool match_helper(TreeNode *r, TreeNode *subr)
    { // matching root
        if (r == nullptr || subr == nullptr)
        {
            return (r == nullptr && subr == nullptr);
        }
        return (r->val == subr->val && match_helper(r->left, subr->left) && match_helper(r->right, subr->right));
    };

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        if (match_helper(root, subRoot))
            return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
// time: O(MN), space: O(M+N)