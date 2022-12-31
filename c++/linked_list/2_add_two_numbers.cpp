// linked list: leetcode medium
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int temp = 0;
        ListNode *sum = new ListNode(0);
        ListNode *newHead = sum;
        while (l1 != nullptr && l2 != nullptr)
        {
            temp = l1->val + l2->val + carry;
            sum->val = temp % 10;
            carry = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 != nullptr && l2 != nullptr)
            {
                sum->next = new ListNode(0);
                sum = sum->next;
            }
        }
        while (l1 != nullptr)
        {
            sum->next = new ListNode(0);
            sum = sum->next;
            temp = l1->val + carry;
            sum->val = temp % 10;
            carry = temp / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            sum->next = new ListNode(0);
            sum = sum->next;
            temp = l2->val + carry;
            sum->val = temp % 10;
            carry = temp / 10;
            l2 = l2->next;
        }
        while (carry != 0)
        {
            sum->next = new ListNode(carry % 10);
            sum = sum->next;
            carry = carry / 10;
        }
        return newHead;
    }
};
// time: O(m,n), space; O(m,n)