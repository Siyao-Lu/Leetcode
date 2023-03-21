// string: leetcode easy
/*
You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.
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
    bool equalFrequency(string word)
    {
        vector<int> counter(26, 0);
        for (auto w : word)
        {
            counter[w - 'a']++;
        }
        for (int i = 0; i < counter.size(); i++)
        {
            if (counter[i] != 0)
            {
                counter[i]--;
                if (helper(counter))
                {
                    return true;
                }
                counter[i]++;
            }
        }
        return false;
    }

private:
    bool helper(vector<int> &counter)
    {
        set<int> counts;
        for (auto c : counter)
        {
            if (c != 0)
            {
                counts.insert(c);
            }
        }
        return (counts.size() == 1) ? true : false;
    }
};
// time: O(n), space: O(n)