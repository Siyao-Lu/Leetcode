// array: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int currMax = nums[0];
        int best = nums[0];
        int currMin = nums[0];
        // similar to leetcode 53 maximum subarray but now additional factor of negative sign
        // 0: restart
        // negative number: currMin to take into account
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = max(nums[i], max(currMax * nums[i], currMin * nums[i]));
            currMin = min(nums[i], min(currMax * nums[i], currMin * nums[i]));
            currMax = temp;
            best = max(currMax, best);
        }
        return best;
    }
};
// time: O(n)
// space: O(1)
