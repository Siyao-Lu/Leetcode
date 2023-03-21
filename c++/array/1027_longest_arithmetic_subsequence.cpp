// array: leetcode medium (DP)
/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the
order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

/*
constraints:
2 <= nums.length <= 1000
0 <= nums[i] <= 500
*/
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> counter(size, vector<int>(1000, 0));
        int seq = 2;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                // diff could be negative
                int diff = nums[j] - nums[i] + 500;
                counter[j][diff] = max(2, counter[i][diff] + 1);
                seq = max(seq, counter[j][diff]);
            }
        }
        return seq;
    }
};
// time: O(n^2), space: O(n^2)