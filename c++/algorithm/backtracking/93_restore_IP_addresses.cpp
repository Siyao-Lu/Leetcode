// backtracking: leetcode medium
/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> results;
    vector<int> dots;
    vector<string> restoreIpAddresses(string s)
    {
        helper(s, 0);
        return results;
    }
    void helper(const string &s, int index)
    {
        int length = s.size();
        int remaining_length = length - index;
        int remaining_num = 4 - dots.size();
        if (remaining_length > remaining_num * 3 || remaining_length < remaining_num)
        {
            return;
        }
        // last address
        if (remaining_num == 1)
        {
            if (valid(s, index, remaining_length))
            {
                string temp = "";
                int offset = 0;
                for (auto d : dots)
                {
                    temp.append(s.substr(offset, d));
                    offset += d;
                    temp.append(".");
                }
                // append last address
                temp.append(s.substr(offset));
                results.push_back(temp);
            }
            return;
        }
        // if not, address can be length 1 - 3
        for (int l = 1; l <= 3 && l <= remaining_length; l++)
        {
            dots.push_back(l);
            if (valid(s, index, l))
            {
                helper(s, index + l);
            }
            dots.pop_back();
        }
    }

private:
    bool valid(const string &s, int start, int len)
    {
        // if length == 1, we can have 0
        // if length == 2, check for non-leading 0
        // if lengh == 3, check for non-leading 0 and <= 255
        return len == 1 || (s[start] != '0' && (len < 3 || s.substr(start, len) <= "255"));
    }
};
// n integers, m digits at most
// time: O(m^n * n); space: O(m*n)