// array: leetcode easy (Blind 75 LeetCode Questions)
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int min = INT_MAX;
        for (auto price : prices)
        {
            if (price < min)
            {
                min = price;
            }
            else
            {
                if (price - min > maxProfit)
                {
                    maxProfit = price - min;
                }
            }
        }
        return maxProfit;
    }
};
// one pass instead of nested for loop
// space complexity: O(1)
// time complexity: O(n) => one pass