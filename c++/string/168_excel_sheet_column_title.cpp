// string: leetcode easy
/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
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

// A - 1, Z - 26, AA - 27
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            result.push_back('A' + columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// time: O(n), space: O(1)