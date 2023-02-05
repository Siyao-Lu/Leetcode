// array: leetcode medium (two pointers)
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
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
    void rotate(vector<int> &nums, int k)
    {
        /*
        1. reverse all
        2. reverse first k
        3. reverse the rest (n-k)
        */
        k %= nums.size();
        reverse(nums, 0, k);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};
// time: O(n), space: O(1)