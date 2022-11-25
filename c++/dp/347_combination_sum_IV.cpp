// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an array of distinct integers nums and a target integer target,
return the number of possible combinations that add up to target.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned> dp(target + 1, 0); // pre-populate dp vector
        for (auto num : nums)
        {
            dp[num] = 1;
        }
        dp[0] = 1; // base case
        for (int i = 1; i <= target; i++)
        {
            for (auto num : nums)
            {
                if (i - num >= 0)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// time: O(t * n): nested for loop
// space: O(n)