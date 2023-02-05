// array: leetcode medium
/*
There is a rectangular brick wall in front of you with n rows of bricks.
The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths.
The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks.
If your line goes through the edge of a brick, then the brick is not considered as crossed.
You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall,
return the minimum number of crossed bricks after drawing such a vertical line.
*/
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        // ex: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
        map<int, int> counts;
        for (auto row : wall)
        {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++)
            {
                sum += row[i];
                counts[sum]++;
            }
        }
        if (counts.empty())
        {
            return wall.size();
        }
        int count = INT_MIN;
        for (auto c : counts)
        {
            count = max(count, c.second);
        }
        return (wall.size() - count);
    }
};
// time: O(n) - # bricks; space: O(m) - wall width