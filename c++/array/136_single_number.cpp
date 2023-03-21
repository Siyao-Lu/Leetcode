// array: leetcode easy
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
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
    int singleNumber(vector<int> &nums)
    {
        int single = 0;
        for (int i : nums)
        {
            single ^= i;
        }
        return single;
    }
};
// time: O(n), space: O(1)
// XOR with itself = 0; XOR with zero = itself