// array: leetcode easy
/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
return the number of negative numbers in grid.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*
staircase strucuture:
    ++++++
    +++---
    ++----
    ------

*/
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int r = row - 1, c = 0, count = 0;
        while (r >= 0 && c < col)
        {
            if (grid[r][c] < 0)
            {
                count += col - c;
                r--;
            }
            else
            {
                c++;
            }
        }
        return count;
    }
};
// time: O(n + m), space: O(1)