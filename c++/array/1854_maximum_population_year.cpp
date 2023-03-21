// array: leetcode easy
/*
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1].
Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// prefix sum, line sweep algorithm
// constraint: year 1950-2050 (101 total)
class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> years(101, 0);
        for (auto log : logs)
        {
            years[log[0] - 1950]++;
            years[log[1] - 1950]--;
        }
        int maxPopulation = years[0], minYear = 1950;
        for (int i = 1; i < 101; i++)
        {
            years[i] += years[i - 1];
            if (years[i] > maxPopulation)
            {
                maxPopulation = years[i];
                minYear = i + 1950;
            }
        }
        return minYear;
    }
};
// time: O(n), space: O(101)