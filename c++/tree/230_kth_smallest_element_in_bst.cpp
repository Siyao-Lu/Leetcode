// tree: leetcode medium (Blind 75 LeetCode Questions)
/*
Given the root of a binary search tree, and an integer k,
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> track;
        while (true)
        {
            while (root != nullptr)
            {
                track.push(root);
                root = root->left;
            }
            root = track.top();
            track.pop();
            k--;
            if (k == 0)
            {
                return root->val;
            }
            root = root->right;
        }
    }
};
// time: O(k) stack; space: O(H + k) tree + stack