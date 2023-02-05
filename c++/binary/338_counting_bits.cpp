// binary, leetcode easy

/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.
*/
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
// time: O(n), space: O(1)