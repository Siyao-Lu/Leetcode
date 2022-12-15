// graph: leetcode medium (Blind 75 LeetCode Questions)
/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and
a list (List[Node]) of its neighbors.
*/
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    void copy_helper(Node *to, Node *from)
    { // copy neighbor array
        to->val = from->val;
        if (from->neighbors.size() != 0)
        {
            for (auto n : from->neighbors)
            {
                Node *next();
                to->neighbors.push_back(next);
                copy_helper(next, n);
            }
        }
    };

    Node *cloneGraph(Node *node)
    {
        Node *copy;
        if (node != nullptr)
        {
            copy_helper(copy, node);
        }
        return copy;
    }
};