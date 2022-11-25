// string: leetcode medium (Blind 75 LeetCode Questions)
/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> track;
        for (auto word : strs)
        {
            track[sortString(word)].push_back(word);
        }
        for (auto t : track)
        {
            results.push_back(t.second);
        }
        return results;
    }

private:
    string sortString(string s)
    {
        int counter[26] = {0};
        for (auto c : s)
        {
            counter[c - 'a']++;
        }
        string sortedString;
        for (int i = 0; i < 26; i++)
        {
            sortedString += string(counter[i], 'a' + i);
        }
        return sortedString;
    }
};
// time O(NK)
// space O(NK)