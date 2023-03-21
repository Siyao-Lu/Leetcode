// array: leetcode medium; 2 pointers
/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int curr_sum = 0;
        int left = 0;
        int length = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            while (curr_sum >= target)
            {
                length = min(length, i + 1 - left);
                curr_sum -= num[left++];
            }
        }
        return (length == INT_MAX) ? 0 : length;
    }
};
// time: O(n), space: O(1)