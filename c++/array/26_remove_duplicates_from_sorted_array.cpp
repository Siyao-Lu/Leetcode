// array: leetcode easy
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates
in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    { // ex 1,2,2,3,4,4,5,5
        int index = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
// space: O(1), time: O(n)