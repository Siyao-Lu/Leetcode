// array: leetcode easy
/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
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
    int missingNumber(vector<int> &nums)
    {
        // range [0 - 6]
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (nums[size - 1] != size)
        {
            return size;
        }
        if (nums[0] != 0)
        {
            return 0;
        }
        //[0, 1, 2, 4, 5, 6]
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                return nums[i - 1] + 1;
            }
        }
        return 0;
    }
};
// time: O(nlogn); space: O(n)