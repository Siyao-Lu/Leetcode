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
#include <unordered_map>
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
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *start = new Node(node->val);
        mp[node] = start;
        for (auto n : node->neighbors)
        {
            if (mp.count(n))
                start->neighbors.push_back(mp[n]);
            else
                start->neighbors.push_back(cloneGraph(n));
        }
        return start;
    }
};
// space: O(N), time: O(N + M) node + edges