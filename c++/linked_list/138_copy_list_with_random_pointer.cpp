// linked list: leetcode medium
// Construct a deep copy of the list
// Definition for a Node.
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
/*
Main challenge: random pointer could point to a node already constructed
Solution: use map to track
*/

class Solution
{
public:
    map<Node *, Node *> track;
    Node *cloneNode(Node *n)
    {
        if (n == nullptr)
            return nullptr;
        if (track.count(n))
        { // already copied
            return track[n];
        }
        Node *temp = new Node(n->val);
        track[n] = temp;
        return temp;
    }

    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *oldNode = head;
        Node *newNode = new Node(oldNode->val);
        Node *newHead = newNode;
        track[oldNode] = newNode;
        while (oldNode != nullptr)
        {
            newNode->next = cloneNode(oldNode->next);
            newNode->random = (oldNode->random == nullptr) ? nullptr : cloneNode(oldNode->random);
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        return newHead;
    }
};
// time: O(n), space: O(n)
// O(1) space can be achieved with old and new nodes interweaving: 1. copy, 2. add random pointers, 3. unweave