// array: leetcode easy
/*
Return the number of columns that you will delete.
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
    int minDeletionSize(vector<string> &strs)
    {
        int len = strs[0].size();
        int del = 0;
        for (int i = 0; i < len; i++)
        {
            for (int s = 0; s < strs.size(); s++)
            {
                if (s == 0 || strs[s - 1][i] <= strs[s][i])
                {
                    continue;
                }
                else
                {
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};
// time: O(m*n) - nested for loop, space: O(1)