// dp: leetcode medium
/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;                   // base case
        vector<int> perfect_squares; // 1, 4, 9, 16
        for (int i = 1; i <= n; i++)
        {
            if (i * i <= n)
            {
                perfect_squares.push_back(i * i);
            }
            else
            {
                break;
            }
        }
        for (int d = 1; d <= n; d++)
        {
            for (int p = 0; p < perfect_squares.size(); p++)
            {
                if (d < perfect_squares[p])
                {
                    break;
                }
                dp[d] = min(dp[d], (dp[d - perfect_squares[p]] + 1));
            }
        }
        return dp[n];
    }
};