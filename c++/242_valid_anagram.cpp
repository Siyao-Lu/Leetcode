// string: leetcode easy (Blind 75 LeetCode Questions)
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> track;
        if (s.size() != t.size())
            return false;
        for (auto character : s)
        {
            track[character]++;
        }
        for (auto t_character : t)
        {
            track[t_character]--;
            if (track[t_character] < 0)
                return false;
        }
        return true;
    }
};
// space: O(n)
// time: O(n)