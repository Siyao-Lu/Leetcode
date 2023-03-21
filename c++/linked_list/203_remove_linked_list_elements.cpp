// linked list: leetcode easy
/*
Given the head of a linked list, return the list after sorting it in ascending order.
*/

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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
// time: O(n), space: O(1)