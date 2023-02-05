// string: leetcode easy
/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        stringstream ss(s);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> tokens(begin, end);
        if (pattern.size() != tokens.size())
        {
            return false;
        }
        unordered_map<char, string> c_s;
        unordered_map<string, char> s_c;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (!c_s.count(pattern[i]) && !s_c.count(tokens[i]))
            {
                c_s[pattern[i]] = tokens[i];
                s_c[tokens[i]] = pattern[i];
            }
            else
            {
                // abba, dog dog dog dog
                // abba, dog cat cat cat
                if (c_s[pattern[i]] != tokens[i] || s_c[tokens[i]] != pattern[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// time: O(n + m) - length of pattern and s; space: O(w) - w = # unique words in s