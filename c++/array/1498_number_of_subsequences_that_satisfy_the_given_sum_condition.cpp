// array: leetcode medium (2 pointer)
/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on
it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.


*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        if (nums[0] > target)
            return 0; // all larger than target
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;
        vector<int> pre = {0, 1};
        for (auto i = pre.size(); i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);
        // any subsequences, we only care abt left and right numbers
        while (left <= right)
        {
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                count = (count + pre[right - left + 1]) % mod;
                left++;
            }
        }
        return count;
    }
};
// time: O(nlogn), space: O(logn)