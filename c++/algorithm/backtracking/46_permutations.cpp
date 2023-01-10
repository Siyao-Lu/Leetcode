// backtracking: leetcode medium
/*
Given an array nums of distinct integers,
return all the possible permutations. You can return the answer in any order.
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
    int size = 0;
    vector<vector<int>> permute(vector<int> &nums)
    {
        size = nums.size();
        if (size == 0)
        {
            return results;
        }
        backtracking(0, nums);
        return results;
    }

private:
    void backtracking(int start, vector<int> &nums)
    {
        if (start == size)
        {
            results.push_back(nums);
            return;
        }
        for (int i = start; i < size; i++)
        {
            swap(nums[i], nums[start]);
            backtracking(start + 1, nums);
            swap(nums[i], nums[start]);
        }
    }
};
// time: O(n * n!), space : O(n!)