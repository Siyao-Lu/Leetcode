// string: leetcode easy (Blind 75 LeetCode Questions)
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack> // LIFO
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> track;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                track.push(c);
            }
            else
            {
                if (c == ')')
                {
                    if (track.empty() || track.top() != '(')
                        return false;
                    track.pop();
                }
                else if (c == '}')
                {
                    if (track.empty() || track.top() != '{')
                        return false;
                    track.pop();
                }
                else // ]
                {
                    if (track.empty() || track.top() != '[')
                        return false;
                    track.pop();
                }
            }
        }
        return track.empty();
    };
};
// time: O(n) - one pass
// space: O(n)