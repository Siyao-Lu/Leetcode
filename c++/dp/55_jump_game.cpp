// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
You are given an integer array nums.
You are initially positioned at the array's first index, and each element in the array represents your maximum jump
length at that position.

Return true if you can reach the last index, or false otherwise.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> memo(nums.size(), false);
        memo[0] = true; // base case
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0 && memo[i])
            { // reachable & jumpable
                int jumps = nums[i];
                while (jumps != 0)
                {
                    if (i + jumps <= nums.size() - 1)
                    {
                        memo[i + jumps] = true;
                        if (i + jumps == nums.size() - 1)
                            break;
                    }
                    jumps--;
                }
            }
        }
        return memo[nums.size() - 1];
    }
};
// space: O(n), time: very inefficient

/*
sample faster solution:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxReachableIndex = 0, n=nums.size();
        for(int i=0;i<n;i++) {
            if(i>mxReachableIndex) return false;
            mxReachableIndex = max(mxReachableIndex,i+nums[i]);
            if(mxReachableIndex>=n-1) return true;
        }

        return mxReachableIndex >= n-1;
    }
};
*/