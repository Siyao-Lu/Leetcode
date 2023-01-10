// backtracking: leetcode medium
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of
candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is
less than 150 combinations for the given input.
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        size = candidates.size();
        vector<int> build;
        int currSum = 0;
        backtracking(0, candidates, build, target, currSum);
        return results;
    }

private:
    void backtracking(int start, vector<int> &candidates, vector<int> &build, int target, int currSum)
    {
        if (currSum == target)
        {
            results.push_back(build);
            return;
        }
        else if (currSum > target)
        {
            return; // too large, will no longer find a match since all value positive
        }
        for (int i = start; i < size; i++)
        {
            build.push_back(candidates[i]);
            currSum += candidates[i];
            backtracking(i, candidates, build, target, currSum);
            build.pop_back();
            currSum -= candidates[i];
        }
    }
};