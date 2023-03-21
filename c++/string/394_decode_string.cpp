// string: leetcode medium
/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there will not be input like 3a or 2[4].
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
    string decodeString(string s)
    {
        string results = "";
        string temp = "";
        stack<char> track;
        for (auto c : s)
        {
            if (c != ']')
            {
                track.push(c);
            }
            else
            { // closing bracket, start decode
                while (track.top() != '[')
                {
                    temp = track.top() + temp;
                    track.pop();
                }
                track.pop(); // pop [ bracket
                // get num
                string num = "";
                while (!track.empty() && isdigit(track.top()))
                {
                    num = track.top() + num;
                    track.pop();
                }
                int iteration = stoi(num);
                while (iteration > 0)
                {
                    results += temp;
                    iteration--;
                }
                for (int i = 0; i < results.size(); i++)
                {
                    track.push(results[i]);
                }
                temp = "";
                results = "";
            }
        }
        results = "";
        while (!track.empty())
        {
            results += track.top();
            track.pop();
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
// https://leetcode.com/problems/decode-string/solutions/858759/decode-string/