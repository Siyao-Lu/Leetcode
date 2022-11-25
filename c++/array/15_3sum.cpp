// array: leetcode medium (Blind 75 LeetCode Questions)
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &result, int index)
    {
        set<int> potential;
        for (int i = index + 1; i < nums.size(); i++)
        {
            int target = 0 - nums[index] - nums[i];
            if (potential.count(target))
            {
                result.push_back({nums[index], nums[i], target});
                while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                { // avoid duplicate
                    i++;
                }
            }
            potential.insert(nums[i]);
        }
    };

    vector<vector<int>> threeSum(vector<int> &nums)
    { // 3 elements sum up to 0; ex [-1,0,1,2,-1,-4]
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // [-4, -1, -1, 0, 1, 2]
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0 && (i == 0 || nums[i] != nums[i - 1]))
            { // if values all positive, no way add to 0 since nums is sorted
                helper(nums, result, i);
            }
        }
        return result;
    }
};
// space: O(n), time: O(n^2)