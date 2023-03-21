// linked list: leetcode easy
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
    bool isPalindrome(ListNode *head)
    {
        // slow and fast pointer to find middle node, then check
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if fast == nullptr -> even; fast->next = nullptr -> odd
        // reverse the right list
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        while (slow)
        {
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        }
        fast = head; // left
        slow = prev; // right (reversed)
        while (slow)
        {
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    };
};
// time: O(n), space: O(1)