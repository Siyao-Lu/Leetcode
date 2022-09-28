// array: leetcode easy (Blind 75 LeetCode Questions)
// Given an integer array nums
// return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> count;
        for (auto num : nums)
        {
            if (count.find(num) == count.end())
            {
                count.insert(num);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// use set to store and later check for duplicates
// num vector size of n:
// time complexity: O(n) => we do n times of find and insert
// space complexity: O(n)