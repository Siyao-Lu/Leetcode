// dp: leetcode medium
/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally,
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int row = 1; row < triangle.size(); row++)
        {
            for (int col = 0; col <= row; col++)
            {
                if (col == 0)
                {
                    triangle[row][col] += triangle[row - 1][col];
                }
                else if (col == row)
                {
                    triangle[row][col] += triangle[row - 1][col - 1];
                }
                else
                {
                    triangle[row][col] += min(triangle[row - 1][col - 1], triangle[row - 1][col]);
                }
            }
        }
        return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    }
};
// time: O(n^2), space: O(1) - in place modification