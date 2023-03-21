// array: leetcode easy
/*
You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> counter(n + 1);
        counter[0] = 0;
        counter[1] = 1;
        int maxNum = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2)
            { // odd
                counter[i] = counter[i / 2] + counter[i / 2 + 1];
                maxNum = max(counter[i], maxNum);
            }
            else
            {
                counter[i] = counter[i / 2];
                maxNum = max(counter[i], maxNum);
            }
        }
        return maxNum;
    }
};
// time: O(n), space: O(n)