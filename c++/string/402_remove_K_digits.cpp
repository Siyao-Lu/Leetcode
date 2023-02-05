// string: leetcode medium
/*
Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int size = num.size();
        if (k >= size)
            return "0";
        if (k == 0)
            return num;
        stack<char> s;
        string final = "";
        for (auto n : num)
        {
            while (!s.empty() && s.top() > n && k > 0)
            {
                s.pop();
                k--;
            }
            if (!s.empty() || n != '0')
                s.push(n);
        }
        while (k > 0 && !s.empty())
        {
            s.pop();
            k--;
        }
        if (s.empty())
            return "0";
        while (!s.empty())
        {
            final.push_back(s.top());
            s.pop();
        }
        reverse(final.begin(), final.end());
        return final;
    }
};
// time: O(n), space: O(n)