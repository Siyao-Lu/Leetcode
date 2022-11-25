// string: leetcode medium (Blind 75 LeetCode Questions)
/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <array>
using namespace std;

// brute force, check all substrings, inefficient => time O(n^3)
class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = s.size();
        for (int i = 0; i < s.size(); i++)
        { // treat each char as the beginning of palindrome and count how many there are
            string counter = "";
            counter += s[i];
            for (int j = i + 1; j < s.size(); j++)
            {
                counter += s[j];
                if (checkValidity(counter))
                    count++;
            }
        }
        return count;
    }

private:
    bool checkValidity(string &target)
    {
        for (int i = 0; i < target.size(); i++)
        {
            if (i > target.size() - 1 - i)
            {
                break;
            }
            if (target[i] != target[target.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
// time: O(n^3)
// space: O(1)

class dp
{
public:
    /*
    basic idea: construct 2D boolean array: db[i][j] tells use
    whether string starting at index i and ending at index j is a palindrom
    */
    int countwithDP(string s)
    {
        int size = s.size();
        int counts = 0;
        bool dp[size][size];
        // base case
        for (int i = 0; i < size; i++)
        {
            dp[i][i] = true;
            counts++;
        }
        // for palindromes size = 2
        for (int i = 0; i < size - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                counts++;
            }
            else
            {
                dp[i][i + 1] = false;
            }
        }
        // for all other sizes
        for (int len = 3; len <= size; ++len)
            for (int i = 0, j = i + len - 1; j < size; ++i, ++j)
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if (dp[i][j])
                    counts++;
            }
        return counts;
    }
};
// time: O(n^2)
// space: O(n^2)