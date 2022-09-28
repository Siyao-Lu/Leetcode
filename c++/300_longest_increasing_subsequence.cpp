// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int longest = 1;
        if (nums.size() == 1)
        {
            return longest;
        }
        vector<int> memo(nums.size(), 1);
        int currMax = nums[0];
        // go through each number, determine the max sublength with the number as the last
        for (int i = 1; i < memo.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    memo[i] = max(memo[i], memo[j] + 1);
                    if (memo[i] > longest)
                        longest = memo[i];
                }
            }
        }
        return longest;
    }
};
// time: O(n^2) - nested for loop
// space: O(n) - memo vector