// array: leetcode easy
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an integer array nums and an integer val,
remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    { // example: [0,1,2,2,3,0,4,2]
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
// time: O(n), space: O(1)