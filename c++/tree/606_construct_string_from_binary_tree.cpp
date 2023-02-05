// tree: leetcode easy
/*
Given the root of a binary tree, construct a string consisting of parenthesis and
integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the
string and the original binary tree.
*/

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
    string tree2str(TreeNode *root)
    {
        string result = "";
        construct(root, result);
        return result;
    }

private:
    void construct(TreeNode *node, string &curr)
    {
        if (node == nullptr)
        {
            return;
        }
        curr += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            return;
        }
        curr += '(';
        construct(node->left, curr);
        curr += ')';
        if (node->right != nullptr)
        {
            curr += '(';
            construct(node->right, curr);
            curr += ')';
        }
        return;
    }
};
// time: O(n), space:O(n)