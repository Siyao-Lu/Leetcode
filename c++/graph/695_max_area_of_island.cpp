// graph: leetcode medium
/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int curr_maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    traverse(grid, r, c);
                    maxArea = (curr_maxArea > maxArea) ? curr_maxArea : maxArea;
                    curr_maxArea = 0;
                }
            }
        }
        return maxArea;
    }

private:
    void traverse(vector<vector<int>> &grid, int curr_r, int curr_c)
    {
        int row = grid.size();
        int col = grid[0].size();
        grid[curr_r][curr_c] = 0;
        curr_maxArea++;
        if (curr_r - 1 >= 0 && grid[curr_r - 1][curr_c] == 1) // check up
        {
            traverse(grid, curr_r - 1, curr_c);
        }
        if (curr_c - 1 >= 0 && grid[curr_r][curr_c - 1] == 1) // check left
        {
            traverse(grid, curr_r, curr_c - 1);
        }
        if (curr_r + 1 < row && grid[curr_r + 1][curr_c] == 1) // check bottom
        {
            traverse(grid, curr_r + 1, curr_c);
        }
        if (curr_c + 1 < col && grid[curr_r][curr_c + 1] == 1) // check right
        {
            traverse(grid, curr_r, curr_c + 1);
        }
    }
};
// same as 200: time: O(MN) row * col; space: worst case O(MN)