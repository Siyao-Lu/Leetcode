// string: leetcode easy (Blind 75 LeetCode Questions)
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string cleaned = "";
        for (char c : s)
        {
            if (isalpha(c))
                cleaned += tolower(c);
            else if (isdigit(c))
                cleaned += c;
        }
        for (int i = 0; i < cleaned.size(); i++)
        {
            if (i > cleaned.size() - 1 - i)
                break;
            if (cleaned[i] != cleaned[cleaned.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

// space: O(n)
// time: O(n); can be more efficient O(1) using two pointers