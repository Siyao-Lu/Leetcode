// tree: leetcode easy
/*
Given the root of a binary search tree and an integer k,
return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
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
    set<int> seen;
    bool findTarget(TreeNode *root, int k)
    {
        return find(root, k);
    }

private:
    bool find(TreeNode *node, int k)
    {
        if (node == nullptr)
            return false;
        if (seen.count(k - node->val))
        {
            return true;
        }
        else
        {
            seen.insert(node->val);
            return (find(node->left, k) || find(node->right, k));
        }
    }
};
// both time and space: O(n)