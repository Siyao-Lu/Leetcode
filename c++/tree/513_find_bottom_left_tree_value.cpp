// tree: leetcode medium
/*
Given the root of a binary tree,
return the leftmost value in the last row of the tree.
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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *leftmost = root;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == nullptr)
            {
                if (!q.empty())
                {
                    leftmost = q.front();
                    q.push(nullptr);
                }
            }
            else
            {
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
        }
        return leftmost->val;
    }
};
// time: O(n); space: O(n)