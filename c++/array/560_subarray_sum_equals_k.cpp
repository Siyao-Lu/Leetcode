// array: leetcode medium (hashing)
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        int size = nums.size();
        unordered_map<int, int> track; // sum: count
        track[0]++;                    // sum 0 : count 1
        for (int i = 0; i < size; i++)
        { // sum: 1, 4, 5, 6, 4, 7, 6, 4  (k = 2)
            sum += nums[i];
            if (track.count(sum - k) != 0)
            {
                count += track[sum - k];
            }
            track[sum]++;
        }

        return count;
    }
};
// time: O(n), space: O(n)