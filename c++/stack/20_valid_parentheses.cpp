// stack and queue: leetcode easy
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> track;
        for (auto paren : s)
        {
            if (paren == '(' || paren == '[' || paren == '{')
            {
                track.push(paren);
            }
            else
            {
                if (paren == ')')
                {
                    if (track.top() == '(')
                    {
                        track.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (paren == ']')
                {
                    if (track.top() == '[')
                    {
                        track.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if (track.top() == '{')
                    {
                        track.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return track.empty();
    };
};
// time: O(n), space: O(n)