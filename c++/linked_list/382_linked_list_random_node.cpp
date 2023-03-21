// linked list: leetcode easy
/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/
// Definition for singly-linked list.

#include <ctime>
#include <cstdlib>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Reservoir Sampling:
keep track of the current randomly selected node and replace it with a new node with probability 1/i (i = index of current node)
*/
class Solution
{
public:
    ListNode *h;
    Solution(ListNode *head)
    {
        h = head;
        srand(time(0)); // seed the random number generator
    }

    int getRandom()
    {
        ListNode *temp = h;
        int chosen;
        int i = 1;
        while (temp != nullptr)
        {
            // random number within range i
            if (rand() % i == 0)
            {
                chosen = temp->val;
            }
            i++;
            temp = temp->next;
        }
        return chosen;
    }
};
// time: O(n), space: O(1)