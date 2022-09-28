// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int longest = 0;
        vector<int> memo(text1.size(), 0);
        // base case
        for (int i = 0; i < text2.size(); i++)
        {
            if (find(text1.begin(), text1.end(), text2[i]) != text1.end())
            { // the character exists in the other string
                int index = find(text1.begin(), text1.end(), text2[i]) - text1.begin();
            }
            for (int j = 0; j < text1.size(); j++)
            {
            }
        }
    }
};