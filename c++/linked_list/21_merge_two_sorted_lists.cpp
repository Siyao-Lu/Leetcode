// linked list: leetcode easy (Blind 75 LeetCode Questions)
/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(-1); // dummy head
        ListNode *counter = head;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            { // add list1
                counter->next = list1;
                list1 = list1->next;
            }
            else
            { // add list2
                counter->next = list2;
                list2 = list2->next;
            }
            counter = counter->next;
        }
        counter->next = list1 == nullptr ? list2 : list1;
        return head->next; // skip dummy head
    }
};
// time: O(m + n) - size of two lists
// space: O(1)