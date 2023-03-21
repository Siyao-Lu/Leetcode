// array: leetcode easy
/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
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
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int greatest = 0;
        for (auto account : accounts)
        {
            int temp = 0;
            for (auto w : account)
            {
                temp += w;
            }
            greatest = max(greatest, temp);
        }
        return greatest;
    }
};
// time: O(m+n), space: O(1)