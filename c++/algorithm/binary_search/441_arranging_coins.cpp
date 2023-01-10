// binary search: leetcode easy
/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows
where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long left = 0;
        long long right = n;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long coins = mid * (mid + 1) / 2; // integer overflow
            if (coins == n)
            {
                return mid;
            }
            else if (coins > n)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
};
// time: O(logn), space: O(1)