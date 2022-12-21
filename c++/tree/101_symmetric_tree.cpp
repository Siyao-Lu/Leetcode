// tree: leetcode easy
/*
Given the root of a binary tree,
check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool checkSymmetry(TreeNode *leftsub, TreeNode *rightsub)
    {
        if (leftsub == nullptr || rightsub == nullptr)
        {
            return leftsub == nullptr && rightsub == nullptr;
        }
        return (leftsub->val == rightsub->val) && checkSymmetry(leftsub->left, rightsub->right) && checkSymmetry(leftsub->right, rightsub->left);
    };

    bool isSymmetric(TreeNode *root)
    {
        // base case
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }
        return checkSymmetry(root->left, root->right);
    }
};
// time: O(n), space: O(n)