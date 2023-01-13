// array: leetcode medium (two pointers)
/*
You are given a 0-indexed array nums of distinct integers.
You want to rearrange the elements in the array such that every element in the rearranged array is not equal
to the average of its neighbors.

More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1,
(nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].

Return any rearrangement of nums that meets the requirements.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> result(size, 0);
        int slow = 0;
        int fast = 0;
        for (; slow < size && fast < size; slow++, fast += 2)
        {
            result[fast] = nums[slow]; // leave one space in between to fill with large number, so both neighbors are smaller
        }
        // fill in the gap
        fast = 1;
        for (; slow < size && fast < size; slow++, fast += 2)
        {
            result[fast] = nums[slow];
        }
        return result;
    }
};
// time: O(nlogn), space: O(logn)