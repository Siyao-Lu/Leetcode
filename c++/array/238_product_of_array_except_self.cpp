// array: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of
all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> results(nums.size(), 1); // result vector
        // forward pass if nums[2, 3, 4, 5] => [1, 2, 6, 24] left result
        int counter = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            counter *= nums[i];
            results[i + 1] = counter;
        }
        counter = 1; // reset counter
        // back pass to get right results
        for (int i = nums.size() - 1; i > 0; i--)
        {
            counter *= nums[i];
            results[i - 1] *= counter;
        }
        return results;
    }
};
// time: O(n) - two passes
// space: O(1) excluding output vector, a counter variable to keep track of right result