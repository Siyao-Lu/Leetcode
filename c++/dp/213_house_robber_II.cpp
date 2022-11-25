// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, a
djacent houses have a security system connected, and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// modification from house_robber: houses are now arranged in circle ABCDE
// rob either ABCD or BCDE
class Solution
{
public:
    int rob_helper(int start, vector<int> &nums, int end)
    {
        int rob1 = 0;
        int rob2 = 0;
        for (int i = start; i <= end; i++)
        {
            int temp = rob1;
            int curr = nums[i];
            rob1 = max(curr + rob2, rob1);
            rob2 = temp;
        }
        return rob1;
    };

    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int first = rob_helper(1, nums, nums.size() - 1);
        int second = rob_helper(0, nums, nums.size() - 2);
        return max(first, second);
    }
};

// time: O(n)
// space: O(1)