// string: leetcode easy
/*
Given a string columnTitle that represents the column title as appears
in an Excel sheet, return its corresponding column number.
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
    int titleToNumber(string columnTitle)
    {
        int result = 0, power = 0;
        /*
        example: AB - 28
        B: 2
        A: 1 * 26^1
        */
        while (columnTitle != "")
        {
            result += (columnTitle.back() - 'A' + 1) * pow(26, power++);
            columnTitle.pop_back();
        }
        return result;
    }
    // time: O(n), space: O(1)
};