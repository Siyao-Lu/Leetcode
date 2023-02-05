// string: leetcode medium
/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
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
    vector<int> findAnagrams(string s, string p)
    {
        int p_size = p.size();
        int s_size = s.size();
        if (s_size < p_size)
            return {};
        vector<int> indices;
        unordered_map<char, int> p_map;
        unordered_map<char, int> s_map;
        for (auto s : p)
        {
            p_map[s]++;
        }
        for (int i = 0; i < p_size; i++)
        {
            s_map[s[i]]++;
        }
        // sliding window
        for (int i = p_size; i < s_size; i++)
        {
            if (s_map == p_map)
            {
                indices.push_back(i - p_size);
            }
            // remove left, add right
            if (s_map[s[i - p_size]] > 1)
            {
                s_map[s[i - p_size]]--;
            }
            else
            {
                s_map.erase(s[i - p_size]);
            }
            s_map[s[i]]++;
        }
        // check last sliding window
        if (s_map == p_map)
        {
            indices.push_back(s_size - p_size);
        }
        return indices;
    }
};
// time: O(n), space: O(k) - at most 26 letters