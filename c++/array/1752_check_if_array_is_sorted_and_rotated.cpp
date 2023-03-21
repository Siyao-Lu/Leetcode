// array: leetcode easy
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order,
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.
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
    bool check(vector<int> &nums)
    {
        int s = nums.size();
        int rotated = 0;
        for (int i = 1; i < s; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                rotated++;
            }
        }
        if (!rotated)
            return true;
        if (rotated == 1 && (nums[0] >= nums[s - 1]))
            return true;
        return false;
    }
};
// time: O(n), space: O(1)