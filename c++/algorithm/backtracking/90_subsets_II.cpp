// backtracking: leetcode medium
/*
Given an integer array nums that may contain duplicates, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> results;
    int size = 0;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // step 1: sort nums vector to later distinguish duplicates
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<int> build;
        backtracking(0, nums, build);
        return results;
    }

private:
    void backtracking(int start, vector<int> &nums, vector<int> &build)
    {
        // Add the subset formed so far to the result.
        results.push_back(build);
        for (int i = start; i < size; i++)
        {
            // ignore duplicates
            if (i != start && nums[i] == nums[i - 1])
            {
                continue;
            }
            build.push_back(nums[i]);
            backtracking(i + 1, nums, build);
            build.pop_back();
        }
    }
};
// time: O(n* 2^n), space: O(n)