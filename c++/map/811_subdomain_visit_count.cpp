// medium
/*
Given an array of count-paired domains cpdomains,
return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> counter;
        vector<string> results;
        for (auto domain : cpdomains)
        {
            auto pos = domain.find(" ");
            string count = domain.substr(0, pos);
            domain = domain.substr(pos + 1);
            stack<string> s;
            while (domain.find(".") != string::npos)
            {
                pos = domain.find(".");
                s.push(domain.substr(0, pos));
                domain = domain.substr(pos + 1);
            }
            // domain now contains the last address
            counter[domain] += stoi(count);
            while (!s.empty())
            {
                domain = s.top() + "." + domain;
                counter[domain] += stoi(count);
                s.pop();
            }
        }
        for (auto c : counter)
        {
            string s = to_string(c.second) + " " + c.first;
            results.push_back(s);
        }
        return results;
    }
};
// time: O(n), space: O(n)