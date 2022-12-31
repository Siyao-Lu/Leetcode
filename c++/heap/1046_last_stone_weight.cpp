// leetcode easy
/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn,
we choose the heaviest two stones and smash them together.
Suppose the heaviest two stones have weights x and y with x <= y.
The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has
new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> weights;
        for (auto stone : stones)
        {
            weights.push(stone);
        }
        while (!weights.empty())
        {
            int larger = weights.top();
            weights.pop();
            if (weights.empty())
                return larger;
            int smaller = weights.top();
            weights.pop();
            if (larger - smaller > 0)
            {
                weights.push(larger - smaller);
            }
        }
        return 0;
    }
};
// time: O(NlogN), space: O(N) or O(NlogN)