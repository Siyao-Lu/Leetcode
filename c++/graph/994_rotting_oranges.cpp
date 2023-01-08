// graph: leetcode medium
/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int time = -1;
        int fresh = 0;
        queue<pair<int, int>> current;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int row = grid.size();
        int col = grid[0].size();
        // step 1: save time 0 rotten coordinates + initial fresh oranges count
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 2)
                {
                    current.push({r, c});
                }
                if (grid[r][c] == 1)
                {
                    fresh++;
                }
            }
        }
        current.push({-1, -1}); // minute marking
        while (!current.empty())
        {
            pair<int, int> coord = current.front();
            current.pop();
            if (coord.first == -1)
            { // we have processed current minute
                time++;
                if (!current.empty())
                {
                    current.push({-1, -1}); // minute marking
                }
            }
            else
            { // process rotten orange, check four directions
                for (auto d : directions)
                {
                    int r = coord.first + d[0];
                    int c = coord.second + d[1];
                    if (r >= 0 && c >= 0 && r < row && c < col && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        fresh--;
                        current.push({r, c});
                    }
                }
            }
        }
        return (fresh == 0) ? time : -1;
    }
};
// time: O(MN), space: O(MN)