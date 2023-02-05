// string: leetcode medium
/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and
equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
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
    string removeDuplicates(string s, int k)
    {
        stack<int> counts;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 || s[i] != s[i - 1])
            {
                counts.push(1);
            }
            else if (++counts.top() == k)
            {
                s.erase(i - k + 1, k);
                counts.pop();
                i -= k;
            }
        }
        return s;
    }
};
// time: O(n), space: O(n)