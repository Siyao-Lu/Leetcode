// array: leetcode medium
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an integer array nums of length n and an integer target, find three integers in nums such that
the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            int potential = target - nums[i];
            while (left < right)
            {
                if (abs(potential - nums[left] - nums[right]) < abs(diff))
                {
                    diff = potential - nums[left] - nums[right];
                }
                // move left, right pointer, too small move left, too big move right
                if (potential - nums[left] - nums[right] < 0)
                { // too big
                    right--;
                }
                else if (potential - nums[left] - nums[right] > 0)
                {
                    left++;
                }
                else
                {
                    return target; // exactly match
                }
            }
        }
        return target - diff;
    }
};
// time: O(n^2); space: O(logn) or O(n) depending on sort algorithm