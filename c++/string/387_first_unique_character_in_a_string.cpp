// string: leetcode easy
/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
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
    int firstUniqChar(string s)
    {
        unordered_map<char, int> counter;
        for (auto c : s)
        {
            counter[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (counter[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// time: O(n), space: O(1)