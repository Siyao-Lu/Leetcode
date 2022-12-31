// leetcode heap medium
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y
plane and an integer k, return the k closest points to the origin (0, 0).
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

class Solution
{
public:
    struct greater
    {
        bool operator()(const pair<int, double> &pair1, const pair<int, double> &pair2)
        {
            return pair2.second > pair1.second;
        }
    };

    double calcDistance(vector<int> coordinates)
    {
        return sqrt(pow(coordinates[0], 2) + pow(coordinates[1], 2));
    };

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, double>, vector<pair<int, double>>, greater> distances;
        vector<vector<int>> results;
        for (int i = 0; i < points.size(); i++)
        {
            if (distances.size() < k)
            {
                distances.push({i, calcDistance(points[i])});
            }
            else
            {
                auto temp = calcDistance(points[i]);
                if (distances.top().second > temp)
                {
                    distances.pop();
                    distances.push({i, temp});
                }
            }
        }
        while (!distances.empty())
        {
            results.push_back(points[distances.top().first]);
            distances.pop();
        }
        return results;
    }
};
// space: O(n), time:(N + klogN)