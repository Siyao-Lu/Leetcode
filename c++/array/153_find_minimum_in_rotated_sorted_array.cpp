// array: leetcode medium (Blind 75 LeetCode Questions)
/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time. => CANNOT use std::find => BINARY SEARCH
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while (right >= left)
        {
            if (nums[left] <= nums[right])
            {
                return nums[left];
            }
            int mid = (left + right) / 2; // integer always round down
            if (nums[left] > nums[mid])
            { // to the left
                right = mid;
            }
            else
                left = mid + 1;
        }
        return INT_MAX;
    }
};
// time: binary search O (logn)
// space: O(1)