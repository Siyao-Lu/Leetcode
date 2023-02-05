// array: leetcode easy
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/

// Boyer-Moore Voting Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate;
        for (auto num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count++;
            }
            else
            {
                count = (num == candidate) ? count + 1 : count - 1;
            }
        }
        return candidate;
    }
};
// time:O(n), space:O(1)