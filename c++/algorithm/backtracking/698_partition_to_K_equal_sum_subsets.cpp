// backtracking: leetcode medium
/*
Given an integer array nums and an integer k, return true if it is possible to
divide this array into k non-empty subsets whose sums are all equal.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

// backtracking with memoization
class Solution
{
public:
    unordered_map<string, bool> memo;
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int size = nums.size();
        int total_sum = 0;
        int count = 0;
        for (auto num : nums)
        {
            total_sum += num;
        }
        if (total_sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        string taken(size, '0'); // 0 not included, 1 included
        return backtrack(nums, 0, 0, total_sum / k, k, taken, count);
    }

private:
    bool backtrack(vector<int> &nums, int index, int curr_sum, int target, int k, string &taken, int count)
    {
        int size = nums.size();
        if (count + 1 == k)
        {
            return true;
        }
        if (curr_sum > target)
        {
            return false;
        }
        if (memo.count(taken))
        {
            return memo[taken];
        }
        // curr_sum = target
        if (curr_sum == target)
        {
            return memo[taken] = backtrack(nums, 0, 0, target, k, taken, count + 1);
        }
        // haven't reached target, pick and backtrack
        for (int i = index; i < size; i++)
        {
            if (taken[i] == '0')
            {
                taken[i] = '1';
                if (backtrack(nums, i + 1, curr_sum + nums[i], target, k, taken, count))
                {
                    return true;
                }
                taken[i] = '0';
            }
        }
        return memo[taken] = false;
    };
};
// time: O(n * 2^n), space: O(n * 2^n)