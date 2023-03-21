// string: leetcode easy
/*
Two strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.

Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.

The frequency of a letter x is the number of times it occurs in the string.
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
    bool checkAlmostEquivalent(string word1, string word2)
    {
        unordered_map<char, int> counter1;
        unordered_map<char, int> counter2;
        for (auto w1 : word1)
        {
            counter1[w1]++;
        }
        for (auto w2 : word2)
        {
            if (counter1.count(w2) && counter1[w2] > 0)
            {
                counter1[w2]--;
            }
            else
            {
                counter2[w2]++;
            }
        }
        for (auto c1 : counter1)
        {
            if (c1.second > 3)
            {
                return false;
            }
        }
        for (auto c2 : counter2)
        {
            if (c2.second > 3)
            {
                return false;
            }
        }
        return true;
    }
};
// time: O(n + m); space: O(n + m)