// dp: leetcode easy (Blind 75 LeetCode Questions)
/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> ways;
        ways.push_back(1);
        ways.push_back(2); // base case
        for (int i = 2; i < n; i++)
        {
            ways.push_back(ways[i - 2] + ways[i - 1]);
        }
        return ways[n - 1];
    }
}; // dp with memoization
   // time: O(n)
   // space: O(n)