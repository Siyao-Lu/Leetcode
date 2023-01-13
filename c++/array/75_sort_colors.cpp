// array: leetcode medium (hashing)
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> colors;
        for (int num : nums)
        {
            colors[num]++;
        }
        // cout << colors[0] << " " << colors[1] << " " << colors[2];
        for (int i = 0; i < nums.size(); i++)
        {
            if (colors[0] > 0)
            {
                nums[i] = 0;
            }
            else if (colors[1] > 0)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
            colors[nums[i]]--;
        }
    }
};
// time: O(n), space: O(n)
// can be optimized with 3 pointer one pass