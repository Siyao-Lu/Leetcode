// dp: leetcode medium (Blind 75 LeetCode Questions)
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (auto coin : coins)
            {
                if (coin <= i)
                {
                    memo[i] = min(memo[i], memo[i - coin] + 1);
                }
            }
        }
        return memo[amount] > amount ? -1 : memo[amount];
    }
};
// suppose coin size of n, memo size of S
// time: O (S * n)
// space: O(S)