// string: leetcode medium (Blind 75 LeetCode Questions)
/*
You are given a string s and an integer k. You can choose any character of the string and
change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxCount = 0;
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> track;
        for (int end = 0; end < s.size(); end++)
        {
            track[s[end]]++;
            maxCount = max(maxCount, track[s[end]]);
            if (end - left + 1 - maxCount > k)
            {
                track[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, end - left + 1);
        }
        return maxLength;
    }
};
// sliding window
// space: O(n)
// time: O(n)