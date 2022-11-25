// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems
connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// cannot rob adjacent houses
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> memo(size, 0);
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        };
        return memo[size - 1];
    }
};

// time: O(n)
// space: O(n), can be optimized to O(1) if we only keep track of present and previous rob values, rather than memo vector