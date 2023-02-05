// stack and queue: leetcode medium
/*
Return the number of car fleets that will arrive at the destination.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int fleets = 0;
        double hours = 0.0;
        map<int, double> times;
        for (int i = 0; i < position.size(); i++)
        {
            times[-position[i]] = (target - position[i]) / (double)speed[i];
        } // negative position so that map is sorted: starting from car furthest from target
        for (auto t : times)
        {
            if (t.second > hours)
            {
                fleets++;
                hours = t.second;
            }
        }
        return fleets;
    }
};
// time: O(n), space: O(n)