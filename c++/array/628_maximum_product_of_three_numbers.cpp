// array: leetcode easy
/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // sorted in ascending order
        int size = nums.size();
        // if all negative, take the last three (basically case 2)
        // case 1: 1 positive * 2 negative
        // case 2: 3 positive
        return max(nums[size - 1] * nums[size - 2] * nums[size - 3], nums[size - 1] * nums[0] * nums[1]);
    }
};
// time: O(nlogn), space: O(nlogn)