// string: leetcode medium
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
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {"()"};
        string left = "(";
        string right = ")";
    }
};