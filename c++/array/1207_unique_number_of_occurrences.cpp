// array: leetcode easy
/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> counts;
        for (auto a : arr)
        {
            counts[a]++;
        }
        set<int> freq; // set

        for (auto c : counts)
        {
            if (!freq.count(c.second))
            {
                freq.insert(c.second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// time: O(n), space: O(n)