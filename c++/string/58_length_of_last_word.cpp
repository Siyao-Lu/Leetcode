// string: leetcode easy
/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
consisting of non-space characters only.
*/
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int size = s.size();
        int length = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (length)
                    return length;
            }
            else
            {
                length++;
            }
        }
        return length;
    }
};
// time: O(n), space: O(1)