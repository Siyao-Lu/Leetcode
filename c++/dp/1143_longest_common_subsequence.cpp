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
    { // example: text1 = "abcde", text2 = "ace"
        int longest = 0;
        vector<vector<int>> memo(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // iterate through 2d vector
        for (int col = text2.size() - 1; col >= 0; col--)
        {
            for (int row = text1.size() - 1; row >= 0; row--)
            {
                if (text2[col] == text1[row])
                { // same character
                    memo[row][col] = 1 + memo[row + 1][col + 1];
                }
                else
                {
                    memo[row][col] = max(memo[row + 1][col], memo[row][col + 1]);
                }
            }
        }
        return memo[0][0];
    }
};
// time: O(MN), space: 2d vector O(MN)