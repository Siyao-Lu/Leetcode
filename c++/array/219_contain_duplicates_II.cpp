// array: leetcode easy
/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j
in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int size = nums.size();
        unordered_map<int, int> counter;
        for (int i = 0; i < size; i++)
        {
            if (!counter.count(nums[i]))
            {
                counter[nums[i]] = i;
            }
            else
            {
                if (i - counter[nums[i]] <= k)
                {
                    return true;
                }
                else
                {
                    counter[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
// time: O(n), space: O(n)