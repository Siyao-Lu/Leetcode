// array: leetcode easy
/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, char> TS;
        unordered_map<char, char> ST;
        for (int i = 0; i < s.size(); i++)
        {
            if ((TS.count(t[i]) && TS[t[i]] != s[i]) || (ST.count(s[i]) && ST[s[i]] != t[i]))
            {
                return false;
            }
            TS[t[i]] = s[i];
            ST[s[i]] = t[i];
        }
        return true;
    }
};
// both time and space: O(n)