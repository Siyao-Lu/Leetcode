// array: leetcode medium
/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
If no land or water exists in the grid, return -1.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

// multisource bfs on land (reverse bfs on water)
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        // add all land cells to queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n)
        {
            return -1;
        }
        // bfs
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int distance = 0;
        while (!q.empty())
        {
            auto coordinate = q.front();
            q.pop();
            for (auto d : dir)
            {
                int x = coordinate.first + d[0];
                int y = coordinate.second + d[1];
                if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0)
                {
                    continue;
                }
                grid[x][y] = grid[coordinate.first][coordinate.second] + 1;
                distance = max(distance, grid[x][y]);
                q.push({x, y});
            }
        }
        return distance - 1;
    }
};
// time: O(n^2), space: O(n^2)