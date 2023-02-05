// tree: leetcode easy
/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced binary search tree.
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
    int size;
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        size = nums.size();
        return construct(nums, 0, size - 1);
    }

private:
    TreeNode *construct(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(nums, start, mid - 1);
        root->right = construct(nums, mid + 1, end);
        return root;
    }
};
// time: O(n), space: O(logn) - balanced tree