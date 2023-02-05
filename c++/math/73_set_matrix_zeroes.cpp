// math: leetcode medium
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> rows;
        set<int> cols;
        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[0].size(); c++)
            {
                if (matrix[r][c] == 0)
                {
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        }
        // second pass
        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[0].size(); c++)
            {
                if (rows.count(r) || cols.count(c))
                {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
// time: O(mn); space:O(mn) - can be improved to O(1) with inplace flag setting