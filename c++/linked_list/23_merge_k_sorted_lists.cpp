// linked list: leetcode medium
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <vector>
#include <queue>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Using priority queue, default max heap, we want min heap
*/
class Solution
{
public:
    struct smaller
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(-1);
        priority_queue<ListNode *, vector<ListNode *>, smaller> pq;
        // push the first element from each list (guaranteed smallest)
        for (auto list : lists)
        {
            if (list != nullptr)
                pq.push(list);
        }
        ListNode *temp;
        ListNode *curr = dummy;
        while (!pq.empty())
        {
            temp = pq.top();
            curr->next = temp;
            curr = curr->next;
            pq.pop();
            if (temp->next != nullptr)
                pq.push(temp->next);
        }
        return dummy->next;
    }
};
// k = # of linked list; N = # nodes => time: O(Nlogk), space: O(k)