// array: leetcode medium
/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
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
    vector<int> findDuplicates(vector<int> &nums)
    {
        /*
        1. all num appears either once or twice
        2. range [1 - n]; size = n; index 0 - (n - 1)
        3. all values are positive
        */
        // abs(nums[i]) - 1; value - 1 => index
        // nums[i] = 7 => nums[7-1] = nums[6]
        // nums[6] positive => nums[6] *= -1
        // nums[6] negative => appeared twice, 7 is duplicate
        vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                duplicates.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] *= -1;
        }
        return duplicates;
    }
};
// time: O(n), space: O(1) in-place modification