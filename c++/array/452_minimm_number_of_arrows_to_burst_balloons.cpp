// array: leetcode medium; Greedy approach
/*
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int arrows = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= end)
            {
                end = min(end, points[i][1])
            }
            else
            {
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};
// sorting: time O(nlogn), space O(n)

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/288049/minimum-number-of-arrows-to-burst-balloons/