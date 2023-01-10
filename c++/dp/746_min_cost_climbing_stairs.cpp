// dp: leetcode easy
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        if (size == 1)
            return cost[0];
        if (size == 2)
            return (cost[0] < cost[1]) ? cost[0] : cost[1];
        vector<int> dp(size, 0);
        for (int i = 2; i < size; i++)
        {
            dp[i] = min(cost[i - 2] + dp[i - 2], cost[i - 1] + dp[i - 1]);
        }
        return min(cost[size - 2] + dp[size - 2], cost[size - 1] + dp[size - 1]);
    }
};
// bottom up tabulation: time O(n), space O(n)