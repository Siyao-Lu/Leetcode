// stack : leetcode medium
/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k]
such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    // i, j, k && num[i] < num[k] < num[j]
    // num: [3, 4, -4, -3, 3]
    // min_v: [3, 3, -4, -4, -4]
public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        stack<int> track;
        vector<int> min_v(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            min_v[i] = min(min_v[i - 1], nums[i]);
        }

        for (int k = nums.size() - 1; k > 0; k--)
        {
            if (nums[k] <= min_v[k])
                continue;
            while (!track.empty() && track.top() <= min_v[k])
            {
                track.pop();
            }
            if (!track.empty() && track.top() < nums[k])
            {
                return true;
            }
            track.push(nums[k]);
        }
        return false;
    }
};
// both time and space: O(n)