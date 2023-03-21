// string: leetcode medium
/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<int> track(26, 0); // 26 letters: a => index 0; b => index 1.....
        int most_frequent = 0;    // find most frequent letter index
        int index = 0;            // greedy: fill most frequent char 0, 2, 4... then odd 1,3,5...
        int size = s.size();
        for (auto c : s)
        {
            if (++track[c - 'a'] > track[most_frequent])
            {
                most_frequent = c - 'a';
            }
        }
        if (track[most_frequent] > (size + 1) / 2)
        {
            return "";
        }
        while (track[most_frequent])
        {
            s[index] = 'a' + most_frequent;
            track[most_frequent]--;
            index += 2;
        }
        for (int j = 0; j < 26; j++)
        {
            while (track[j])
            {
                if (index >= size)
                {
                    index = 1;
                }
                s[index] = 'a' + j;
                track[j]--;
                index += 2;
            }
        }
        return s;
    }
};
// time: O(n), space: O(1)
// https://leetcode.com/problems/reorganize-string/solutions/335312/c-beat-100/