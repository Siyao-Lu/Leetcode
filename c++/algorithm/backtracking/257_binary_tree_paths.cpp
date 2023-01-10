// backtracking: leetcode easy
/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
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
    vector<string> results;
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string path = "";
        backtracking(root, path);
        return results;
    }
    void backtracking(TreeNode *node, string path)
    {
        if (node != nullptr)
        {
            path += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr)
            {
                results.push_back(path);
            }
            else
            {
                path += "->";
                backtracking(node->left, path);
                backtracking(node->right, path);
            }
        }
    }
};
// time: O(n), space: O(logn)