// array: leetcode medium
/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
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
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        bool changed = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= nums[i - 1])
            {
                continue;
            }
            else
            {
                // 1 1 2 1 1 => 1 1 1 1 1
                // 1 1 2 0 3 => 1 1 2 2 3
                // 1 1 2 0 3 0 => 1 1 2 3 3 0 (changed = true)
                if (!changed)
                {
                    if (i == 1 || nums[i - 2] <= nums[i])
                    {
                        nums[i - 1] = nums[i];
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                    }
                    changed = true;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
// time: O(n), space: O(1)