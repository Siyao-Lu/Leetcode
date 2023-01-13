// dp: leetcode medium
/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before
each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum; // sum will also be used as offset to offset negative sum
        if (sum < abs(target))
            return 0;
        vector<vector<int>> dp(1 + size, vector<int>(sum + offset + 1, 0));
        dp[0][offset] = 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = nums[i]; j < sum * 2 + 1 - nums[i]; j++)
            {
                if (dp[i][j])
                {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        return dp[size][target + offset]; // sum up to 0 after adding the sum offset
    }
};
// time: O(mn), space: O(mn) (m = sum of array, n = length of array)