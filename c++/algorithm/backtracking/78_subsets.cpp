// backtracking: leetcode medium
/*
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> results;
    int length = 0;
    int size = 0;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        size = nums.size();
        vector<int> build;
        for (int i = 0; i <= size; ++i)
        { // empty, size 1, size 2, full size (nums.size())
            length = i;
            backtracking(0, nums, build);
            build.clear();
        }
        return results;
    }

private:
    void backtracking(int start, vector<int> &nums, vector<int> &build)
    {
        if (build.size() == length)
        {
            results.push_back(build);
            return;
        }
        for (int i = start; i < size; i++)
        {
            build.push_back(nums[i]);
            backtracking(i + 1, nums, build);
            build.pop_back();
        }
    }
};
// time: O(n* 2^n), space: O(n)