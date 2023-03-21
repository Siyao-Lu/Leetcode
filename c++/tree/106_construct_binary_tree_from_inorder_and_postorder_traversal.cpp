// tree: leetcode medium
/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
postorder: left right root (last node always the root)
*/
class Solution
{
public:
    unordered_map<int, int> counter;
    int post_index;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 1. find root at last node of postorder
        // 2. find position of root in inorder, left of it must be left subtree, right of it must be right subtree (store index in a map)
        // 3. recursively build, for every subtree, rightmost node in postorder must be root
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            counter[inorder[i]] = i; // val to index
        }
        post_index = size - 1;
        return helper(inorder, postorder, 0, size - 1);
    }

private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int in_start, int in_end)
    {
        if (in_start > in_end || post_index < 0)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[post_index--]);
        int index = counter[root->val];                              // index of root in inorder
        root->right = helper(inorder, postorder, index + 1, in_end); // build right subtree first since postorder is left right root, traversing backward, order right first
        root->left = helper(inorder, postorder, in_start, index - 1);
        return root;
    };
};
// time: O(n), space: O(n)