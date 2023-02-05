// array: leetcode easy
/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
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
    int pivotIndex(vector<int> &nums)
    {
        // first pass: find total
        int left_total = 0;
        int right_total = 0;
        for (auto num : nums)
        {
            right_total += num;
        }
        // second pass
        for (int i = 0; i < nums.size(); i++)
        {
            right_total -= nums[i];
            if (i != 0)
            {
                left_total += nums[i - 1];
            }
            if (right_total == left_total)
            {
                return i;
            }
        }
        return -1;
    }
};
// time: O(n), space: O(1)