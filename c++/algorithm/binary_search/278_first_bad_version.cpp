// binary search: leetcode easy
/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version); // true if bad, false if not bad

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, mid = 1;
        int right = n;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (!isBadVersion(mid))
            {
                // not bad
                left = mid + 1;
            }
            else
            {
                // bad, might not be the first instance
                right = mid;
            }
        }
        return left;
    }
};
// time: O(logn), space: O(1)