// array: leetcode easy
/*
Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that
actually receive mails.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> seen;
        int count = 0;
        for (string email : emails)
        {
            auto at = email.find("@"); // position
            string local = email.substr(0, at);
            string domain = email.substr(at);
            // check local
            auto plus = local.find("+");
            if (plus != string::npos)
            {
                local = local.substr(0, plus);
            }
            string cleaned = "";
            for (auto c : local)
            {
                if (c != '.')
                {
                    cleaned += c;
                }
            }
            string final = cleaned + domain;
            if (!seen.count(final))
            {
                seen.insert(final);
                count++;
            }
        }
        return count;
    }
};
// both time, space: O(MN) - N: vector size, M: each email characters