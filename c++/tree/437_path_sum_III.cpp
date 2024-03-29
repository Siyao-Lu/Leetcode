// tree: leetcode medium
/*
Given the root of a binary tree and an integer targetSum,
return the number of paths where the sum of the values along the path equals
targetSum.

The path does not need to start or end at the root or a leaf,
but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/

#include <algorithm>
#include <map>
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
    int count = 0;
    map<long int, long int> m;

    void find(TreeNode *node, int targetSum, long int currSum)
    {
        if (node == nullptr)
            return;
        currSum += node->val;
        if (currSum == targetSum)
        {
            count = count + m[0] + 1;
        }
        else
        {
            if (m.count(currSum - targetSum))
            {
                count += m[currSum - targetSum];
            }
        }
        m[currSum]++;
        find(node->left, targetSum, currSum);
        find(node->right, targetSum, currSum);
        m[currSum]--; // restore
    };
    int pathSum(TreeNode *root, int targetSum)
    {
        find(root, targetSum, 0);
        return count;
    }
};
// prefix method
// time: O(n), space: O(n)