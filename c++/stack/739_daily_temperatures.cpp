// stack and queue: leetcode medium
/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait
after the ith day to get a warmer temperature. If there is no future day for which
this is possible, keep answer[i] == 0 instead.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// Monotonic stacks are a good option when a problem involves
// comparing the size of numeric elements, with their order being relevant.
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int days = temperatures.size();
        vector<int> results(days, 0); // last entry always 0
        stack<int> s;
        for (int i = 0; i < days; i++)
        {
            int curTemp = temperatures[i];
            while (!s.empty() && temperatures[s.top()] < curTemp)
            {
                int temp = s.top();
                results[temp] = i - temp;
                s.pop();
            }
            s.push(i);
        }
        return results;
    }
};
// time: O(n), space: O(n)