// binary search: leetcode easy
/*
Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // example: nums = [-1,0,3,5,9,12], target = 9
        if (nums.size() == 0)
            return -1;
        int found = -1;
        int left = 0;
        int right = nums.size() - 1; // left = 0; right = 5;
        while (left <= right)
        {
            int mid = (left + right) / 2; // mid = 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            { // >
                right = mid - 1;
            }
        }
        return found;
    }
};
// time: O(logn), space: O(1)