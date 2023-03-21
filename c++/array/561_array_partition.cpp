// array: leetcode easy
/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
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
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            sum += min(nums[i], nums[i + 1]);
            i++;
        }
        return sum;
    }
};
// time: O(nlogn), space: O(n)