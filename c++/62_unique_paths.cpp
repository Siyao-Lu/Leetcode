// dp: leetcode medium (Blind 75 LeetCode Questions)

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot
can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 || col == 0)
                {
                    memo[row][col] = 1; // base case + on the perimeter => only 1 way since moving down or right
                }
                // both row & col != 0
                else
                {
                    memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
                }
            }
        }
        return memo[m - 1][n - 1];
    }
};
// time: O(mn), space: O(mn)