// string: leetcode medium (Blind 75 LeetCode Questions)
// Given a string s, find the length of the longest substring without repeating characters.
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {                                          // sliding window approach, left and right pointer
        unordered_map<char, queue<int>> track; // char and its corresponding index
        if (s.empty())
            return 0;
        if (s.size() == 1)
            return 1;
        int left = 0;
        int right = 0;
        int longest = 0;
        while (right < s.size())
        {
            track[s[right]].push(right);
            if (track[s[right]].size() > 1)
            {
                int duplicate = track[s[right]].front();
                track[s[right]].pop();
                left = left > duplicate ? left : duplicate + 1;
            }
            // no duplicate, store longest length
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};
// time: O(n)
// space: O(n)