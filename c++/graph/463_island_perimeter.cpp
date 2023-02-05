// graph: leetcode easy
/*
ou are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
Determine the perimeter of the island.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int counts = 0;
        int overlap = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] == 1)
                { // each cell only checks left and up
                    counts++;
                    if (r != 0 && grid[r - 1][c] == 1)
                    {
                        overlap++;
                    }
                    if (c != 0 && grid[r][c - 1] == 1)
                    {
                        overlap++;
                    }
                }
            }
        }
        return 4 * counts - 2 * overlap;
    }
};
// time: O(mn), space: O(1)