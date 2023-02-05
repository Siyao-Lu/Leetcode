// tree: leetcode medium
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both
p and q as descendants (where we allow a node to be a descendant of itself).”
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

/*
case 1: common ancestor != p, q
case 2: p common ancestor, q in p's right subtree (p < q)
case 3: p common ancestor, q in p's left subtree (p > q)
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int curr = root->val;
        int p_val = p->val;
        int q_val = q->val;
        if (curr > p_val && curr > q_val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (curr < p_val && curr < q_val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
// both time and space: O(n)