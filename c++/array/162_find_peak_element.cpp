// array: leetcode medium
/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return 0; // one element
        // check for strictly increasing or decreasing array (tails)
        if (nums[0] > nums[1])
            return 0;
        if (nums[size - 1] > nums[size - 2])
            return size - 1;
        int left = 1, right = size - 2; // tails are left out, checked above
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid; // peak
            else if (nums[mid] < nums[mid - 1])
                right = mid - 1; // peak lies on the left side
            else if (nums[mid] < nums[mid + 1])
                left = mid + 1; // lies on the right side
        }
        return -1;
    }
};
// time: O(logn), space: O(1)