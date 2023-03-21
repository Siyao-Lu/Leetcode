// linked list: leetcode medium
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

// 2 pointers to find middle element
// merge sort two halves
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now the middle element
        temp->next = nullptr;
        ListNode *left = sortList(head);  // left half
        ListNode *right = sortList(slow); // right half
        return mergeList(left, right);
    }

private:
    ListNode *mergeList(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        if (head1->val < head2->val)
        {
            head1->next = mergeList(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeList(head1, head2->next);
            return head2;
        }
    }
};
// time: O(n), space: O(1)