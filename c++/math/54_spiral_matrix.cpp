// math: leetcode medium
/*
Given an m x n matrix, return all elements of the matrix in spiral order.
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // direction: go right, down, left, up
        vector<int> results;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int up = 0;
        int right = cols - 1;
        int down = rows - 1;
        while (results.size() < rows * cols)
        {
            for (int i = left; i <= right; i++)
            {
                results.push_back(matrix[up][i]);
            }
            for (int j = up + 1; j <= down; j++)
            {
                results.push_back(matrix[j][right]);
            }
            // Make sure we are now on a different row.
            if (up != down)
            {
                // Traverse from right to left.
                for (int k = right - 1; k >= left; k--)
                {
                    results.push_back(matrix[down][k]);
                }
            }
            // Make sure we are now on a different column.
            if (left != right)
            {
                // Traverse upwards.
                for (int l = down - 1; l > up; l--)
                {
                    results.push_back(matrix[l][left]);
                }
            }
            up++;
            down--;
            right--;
            left++;
        }

        return results;
    }
};
// time: O(MN), space: O(1)