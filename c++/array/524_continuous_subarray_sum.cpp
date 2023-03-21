// array: leetcode medium
/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

// prefix
// If k = 5, then 6 % 5 = 1, which also means (6 + 5) % 5 = 1, save remainder: index ended in map
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> counter{{0, -1}}; // handle edge case where index = 0 is a number divisible by k
        int remainder = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            remainder = (remainder + nums[i]) % k;
            if (!counter.count(remainder))
            {
                counter[remainder] = i;
            }
            else if (i - counter[remainder] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};
// time: O(n) - n is size of nums; space: O(min(n, k)) - at most k possible remainders