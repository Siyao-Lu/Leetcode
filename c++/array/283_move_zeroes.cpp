// array: leetcode easy (2 pointers)
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int non_zero = 0, i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[non_zero++], nums[i]);
            }
        }
    }
};
// time: O(n), space:O(1)