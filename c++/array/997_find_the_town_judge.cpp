// array: leetcode easy
/*
Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (trust.size() < n - 1)
        {
            return -1;
        }
        vector<int> people(n + 1, 0);
        for (auto t : trust)
        {
            people[t[0]]--;
            people[t[1]]++;
        }
        for (int p = 1; p < people.size(); p++)
        {
            if (people[p] == n - 1)
            {
                return p;
            }
        }
        return -1;
    }
};
// time: O(E) - edges; space: O(L) - length of n