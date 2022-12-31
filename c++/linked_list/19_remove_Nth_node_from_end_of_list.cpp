// linked list: leetcode medium
/*
Given the head of a linked list,
remove the nth node from the end of the list and return its head.
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

// one pass, two pointers method (easier method is two pass, finding total length first)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // base simply case
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *first = head;
        ListNode *second = head;
        int temp = 0;
        while (temp != n + 1)
        {
            first = first->next;
            temp++;
            if (first == nullptr)
            { // removing the first or second
                if (temp == n + 1)
                {
                    head->next = head->next->next;
                    return head;
                }
                return head->next;
            }
        }
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
};
// time: O(n), space: O(1)