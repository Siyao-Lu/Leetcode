// graph: leetcode medium
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int islands = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == '1')
                {
                    islands++;
                    traverse(grid, r, c);
                }
            }
        }
        return islands;
    }

private:
    void traverse(vector<vector<char>> &grid, int curr_r, int curr_c)
    {
        int row = grid.size();
        int col = grid[0].size();
        grid[curr_r][curr_c] = '0';
        if (curr_r - 1 >= 0 && grid[curr_r - 1][curr_c] == '1') // check up
        {
            traverse(grid, curr_r - 1, curr_c);
        }
        if (curr_c - 1 >= 0 && grid[curr_r][curr_c - 1] == '1') // check left
        {
            traverse(grid, curr_r, curr_c - 1);
        }
        if (curr_r + 1 < row && grid[curr_r + 1][curr_c] == '1') // check bottom
        {
            traverse(grid, curr_r + 1, curr_c);
        }
        if (curr_c + 1 < col && grid[curr_r][curr_c + 1] == '1') // check right
        {
            traverse(grid, curr_r, curr_c + 1);
        }
    };
};
// time: O(row*col) = O(MN); space: worst case O(MN)