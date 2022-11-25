// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
Given a string s containing only digits, return the number of ways to decode it.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    { // sum up single digit and double digit options, 0 is not a single digit candidate
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s.at(0) == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                dp[i + 1] += dp[i];
            }
            string double_dig = "";
            double_dig += s[i - 1];
            double_dig += s[i];
            if (stoi(double_dig) >= 10 && stoi(double_dig) <= 26)
            {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};
// time O(n), space O(n)