// array: leetcode easy
/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x
is in one of the ranges but not in nums.
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
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        vector<string> ranges;
        int curr = nums[0], temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == curr + 1)
            {
                curr = nums[i];
            }
            else
            {
                // end of a segment
                if (curr == temp)
                {
                    ranges.push_back(to_string(curr));
                }
                else
                {
                    ranges.push_back(to_string(temp) + "->" + to_string(curr));
                }
                curr = nums[i];
                temp = nums[i];
            }
        }
        // check last segment
        if (curr == temp)
        {
            ranges.push_back(to_string(curr));
        }
        else
        {
            ranges.push_back(to_string(temp) + "->" + to_string(curr));
        }
        return ranges;
    }
};
// time: O(n), space: O(1)