// array: leetcode medium (Blind 75 LeetCode Questions)
#include <vector>
#include <algorithm>
using namespace std;

/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
(1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
(0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // case 1: no rotation, all ascending
        // case 2: rotation: ascending, decrease, then ascending
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int mid = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[left])
            {
                // left sorted 0,1,2,4,5 or 1,2,4,5,0
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                // 4,5,0,1,2 or 5,0,1,2,4
                if (target > nums[mid] && target < nums[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// time: O(log n); space: O(1)