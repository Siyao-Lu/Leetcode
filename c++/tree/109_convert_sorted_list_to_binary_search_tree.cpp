// tree: leetcode medium
/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.
*/

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        return helper(head, nullptr);
    }

private:
    TreeNode *helper(ListNode *start, ListNode *end)
    {
        if (start == end)
            return nullptr;
        ListNode *slow = start, *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        } // slow is now middle node
        TreeNode *root = new TreeNode(slow->val);
        root->left = helper(start, slow);
        root->right = helper(slow->next, end);
        return root;
    }
};
// time, space: O(nlogn)   -- like a binary search, split into left and right