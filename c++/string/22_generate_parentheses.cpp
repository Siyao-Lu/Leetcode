// string/stack/backtracking: leetcode medium
/*
Given n pairs of parentheses, write a function to generate all
combinations of well-formed parentheses.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> total;
    vector<string> generateParenthesis(int n)
    {
        string curr = "";
        backtracking(curr, 0, 0, n);
        return total;
    }
    void backtracking(string curr, int open, int close, int max)
    {
        if (curr.length() == 2 * max)
        {
            total.push_back(curr);
            return;
        }
        if (open < max)
        {
            curr += "(";
            backtracking(curr, open + 1, close, max);
            curr.pop_back();
        }
        if (close < open)
        {
            curr += ")";
            backtracking(curr, open, close + 1, max);
            curr.pop_back();
        }
    }
};
// both time and space: O(4^n/sqrt(n))