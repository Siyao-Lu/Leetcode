// dp: leetcode easy
/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> results;
        results.push_back({1});
        // base cases
        if (numRows == 1)
            return results;
        results.push_back({1, 1});
        if (numRows == 2)
            return results;
        for (int i = 3; i <= numRows; i++)
        {
            results.push_back(vector<int>(i, 1));
            for (int j = 1; j < i - 1; j++)
            {
                results[i - 1][j] = results[i - 2][j - 1] + results[i - 2][j];
            }
        }
        return results;
    }
};
// time: O(numrow^2), space: O(1)