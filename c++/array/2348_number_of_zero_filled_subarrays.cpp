// medium
/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long total = 0, curr_total = 0;
        for (auto num : nums)
        {
            if (num == 0)
            {
                curr_total++;
            }
            else
            {
                curr_total = 0;
            }
            total += curr_total;
        }
        return total;
    }
};
// time: O(n), space: O(1)