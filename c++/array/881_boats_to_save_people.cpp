// array: leetcode medium
/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats
where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time,
provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int total = 0;
        while (left <= right)
        {
            if (people[right] == limit || people[left] + people[right] > limit)
            {
                right--; // heavy person one boat
            }
            else
            {
                right--;
                left++;
            }
            total++;
        }
        return total++;
    }
};
// time: O(NlogN), space: O(logN) - c++ sort