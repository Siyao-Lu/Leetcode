// array: leetcode medium
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result = {-1, -1};
        if (nums.size() == 0)
            return result;
        if (nums.size() == 1 && nums[0] == target)
            return {0, 0};
        else
        {
            int left = 0;
            int right = nums.size() - 1;
            bool found = false;
            while (!found && (left < right))
            {
                if (nums[left] < target)
                {
                    left++;
                }
                if (nums[right] > target)
                {
                    right--;
                }
                if (nums[left] == target && nums[right] == target)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                result[0] = left;
                result[1] = right;
            }
        }
        return result;
    }
};
// time: O(logn), space: O(1)