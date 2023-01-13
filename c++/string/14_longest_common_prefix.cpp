// string: leetcode easy
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string common = "";
        char current;
        for (int i = 0; i < strs[0].size(); i++)
        {
            current = strs[0][i];
            for (int str = 1; str < strs.size(); str++)
            {
                if (i >= strs[str].size() || strs[str][i] != current)
                {
                    return common;
                }
            }
            common += current;
        }
        return common;
    }
};
// time: O(N) - N = sum of all characters in all strings; space: O(1)