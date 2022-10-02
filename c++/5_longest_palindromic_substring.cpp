// string: leetcode medium (Blind 75 LeetCode Questions)
/*
Given a string s, return the longest palindromic substring in s.

A string is called a palindrome string if the reverse of that string is the same as the original string.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty() || s.size() == 1)
            return s;
        int maxLength = 0;
        int currLength = 0;
        int center = 0;
        bool even = true;
        for (int right = 0; right < s.size(); right++)
        { // size can be odd or even
            int evenCenter = checkEachIndex(s, right, right + 1);
            int oddCenter = checkEachIndex(s, right, right);
            currLength = max(evenCenter, oddCenter);
            if (currLength > maxLength && currLength == evenCenter)
            {
                maxLength = currLength;
                center = right;
                even = true;
            }
            else if (currLength > maxLength && currLength == oddCenter)
            {
                maxLength = currLength;
                center = right;
                even = false;
            }
        }
        if (even)
        {
            return s.substr(center - (maxLength / 2) + 1, maxLength);
        }
        // odd
        return s.substr(center - (maxLength / 2), maxLength);
    }

private:
    int checkEachIndex(string &s, int left, int right)
    { // left == right => odd size; left != right => even size
        int temp_left = left;
        int temp_right = right;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (temp_left == left && temp_right == right)
            return 0; // no change
        // correct one off error
        left += 1;
        right -= 1;
        return right - left + 1; // longest palindromic string based on given centers
    }
};
// time: O(n^2)
// space: O(1)