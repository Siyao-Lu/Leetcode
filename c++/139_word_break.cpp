// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> words(wordDict.begin(), wordDict.end());
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;                   // empty word break is always valid
        for (int i = 1; i <= size; i++) // for every i position, check if a word ending here is valid
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (dp[j] && words.find(s.substr(j, i - j)) != words.end())
                {
                    dp[i] = true;
                    break; // as long as it's true, move on to next position
                }
            }
        }
        return dp[size];
    }
};
/*
Example, to make dp[4] true, we can either have no word break, word break at dp[1], at dp[2], dp[3]; as long as one of the options is true, dp[4] is true (bottom up approach)
*/

// space: O(n)
// time: O(n^3): nested for loop, and substr operation that takes O(n)