// string: leetcode medium
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stack>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> combinations;
    unordered_map<char, string> counter;
    vector<string> letterCombinations(string digits)
    {
        counter['2'] = "abc";
        counter['3'] = "def";
        counter['4'] = "ghi";
        counter['5'] = "jkl";
        counter['6'] = "mno";
        counter['7'] = "pqrs";
        counter['8'] = "tuv";
        counter['9'] = "wxyz"; // initialization

        if (digits.size() == 0)
            return combinations;

        string curr = "";
        backtrack(0, curr, digits);
        return combinations;
    }

private:
    void backtrack(int index, string curr, string digits)
    {
        if (curr.size() == digits.size())
        {
            combinations.push_back(curr);
            return;
        }
        string possible = counter[digits[index]];
        for (int c = 0; c < possible.size(); c++)
        {
            curr += possible[c];
            backtrack(index + 1, curr, digits);
            curr.pop_back();
        }
    };
};
// time: O(4^n * n), space: O(n)