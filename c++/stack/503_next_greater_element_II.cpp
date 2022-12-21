// stack and queue: leetcode medium
/*
Given a circular integer array nums (i.e., the next element of
nums[nums.length - 1] is nums[0]), return the next greater number for every
element in nums.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> track;
        int size = nums.size();
        vector<int> results(size, -1);
        for (int i = 0; i < 2 * size; i++)
        {
            while (!track.empty() && nums[track.top()] < nums[i % size])
            {
                results[track.top()] = nums[i % size];
                track.pop();
            }
            if (i < size)
            {
                track.push(i);
            }
        }
        return results;
    }
};
// time: O(n), space: O(n)