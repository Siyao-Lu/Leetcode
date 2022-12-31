// array: leetcode medium
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;
/*
Given an unsorted array of integers nums,
return the length of the longest consecutive elements sequence.
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int longest = 1;
        int val = INT_MAX;
        int currLongest = 1;
        set<int> s;
        for (auto num : nums)
        {
            if (!s.count(num))
            {
                s.insert(num);
            }
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (val == INT_MAX)
            {
                val = *it;
            }
            else
            {
                if (val + currLongest == *it)
                {
                    currLongest++;
                }
                else
                {
                    longest = (currLongest > longest) ? currLongest : longest;
                    currLongest = 1;
                    val = *it;
                }
            }
        }
        return (currLongest > longest) ? currLongest : longest;
    }
};
// space: O(n), time: O(n)
/*
if set not sorted, for every element, check if element - 1 exists, if it doesn't exist,
it can potentially be the start of the sequence (then check element + 1, +2, +3)
*/