// string: leetcode medium
/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order among all possible results.
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
    string removeDuplicateLetters(string s)
    {
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        stack<char> counter;
        string cleaned = "";
        for (int i = 0; i < s.size(); i++)
        {
            lastIndex[s[i] - 'a'] = i;
            // keep track of last seen index for each char, when inserting into stack, check lastIndex for insertion order
        }
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (seen[index])
            {
                continue; // already considered, move on
            }
            while (!counter.empty() && counter.top() > s[i] && i < lastIndex[counter.top() - 'a'])
            {
                // if stack top is lexigraphically larger and there is later occurence, remove
                seen[counter.top() - 'a'] = false;
                counter.pop();
            }
            counter.push(s[i]);
            seen[index] = true;
        }
        while (!counter.empty())
        {
            cleaned += counter.top();
            counter.pop();
        }
        reverse(cleaned.begin(), cleaned.end());
        return cleaned;
    }
};
// time: O(n), space: O(1) - 26 characters