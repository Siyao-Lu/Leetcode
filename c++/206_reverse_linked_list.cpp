// linked list: leetcode easy (Blind 75 LeetCode Questions)
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    { // iterative approach
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev; // this is now the tail
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
// time: O(n)
// space: O(1)