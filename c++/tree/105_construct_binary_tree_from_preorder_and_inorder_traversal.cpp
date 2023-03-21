// tree: leetcode medium
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the
inorder traversal of the same tree, construct and return the binary tree.
*/
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <vector>
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
inorder: left root right
preorder: root left right
*/
class Solution
{
public:
    unordered_map<int, int> counter;
    int pre_index = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        /*
        1. root is first node of preorder
        2. find root in inorder, left is left subtree and right is right subtree
        */
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            counter[inorder[i]] = i; // node val to inorder index
        }
        return helper(preorder, 0, size - 1);
    }

private:
    TreeNode *helper(vector<int> &preorder, int start, int end)
    {
        if (start > end || pre_index > preorder.size())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_index++]);
        int index = counter[root->val]; // find index in inorder
        root->left = helper(preorder, start, index - 1);
        root->right = helper(preorder, index + 1, end);
        return root;
    }
};
// time: O(n), space: O(n)