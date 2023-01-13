// array: leetcode medium (sliding window)
/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and i
ncrement the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// check for valid window: sum + k < (long)A[j] * (j - i + 1)
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j;
        long sum = k;
        for (j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];
            if (sum < (long)nums[j] * (j - i + 1))
                sum -= nums[i++];
        }
        return j - i;
    }
};
// time: O(nlogn), space: O(n)