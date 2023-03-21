// dp: leetcode medium
/*
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
*/
#include <vector>
#include <algorithm>
using namespace std;

/*
for a tromino to fill up the space, it's either
YTT             YYT
YYT     OR      YTT        either way they are symmetrical, so there are only 2 states

for domino to fill up the space, it is either
i - 1: add 1 vertically
i - 2: add 2 horizontally
YYD         YTT
YYD    or   YTT

state 0 = completely filled
state 1 = partially filled (either first row or second row empty)
dp[i][0] = dp[i - 1][0] + dp[i - 2][0] (add domino) + 2 * dp[i - 1][1] (add tromino either fill first or second row)
dp[i][1] = dp[i - 2][0] (add tromino) + dp[i - 1][1] (add domino) => gives partially filled
*/
class Solution
{
public:
    int numTilings(int n)
    {
        const int mod = 1000000007;
        long int dp[n + 1][2];
        // base case
        dp[0][0] = dp[1][0] = 1;
        dp[0][1] = dp[1][1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % mod;
        }
        return dp[n][0];
    }
};
// time: O(n), space: O(n)