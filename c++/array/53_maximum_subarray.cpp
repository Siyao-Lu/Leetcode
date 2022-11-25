// array: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/
#include <vector>
#include <algorithm>
using namespace std;

// basic idea retain subarray as long as it is positive
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int bestMax = nums[0];
        int currMax = nums[0];
        if (nums.size() == 1)
        {
            return nums[0];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            int potential = nums[i];
            currMax = max(potential, potential + currMax); // check whether current number is counted in current maximum
            bestMax = max(bestMax, currMax);
        }
        return bestMax;
    }
};
// time: O(n) - one pass
// space: O(1) -  2 variables to keep track