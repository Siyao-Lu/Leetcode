// array: leetcode easy
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and
two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.
*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1; // nums1
        int p2 = n - 1; // nums2
        for (int p3 = m + n - 1; p3 >= 0; p3--)
        {
            if (p2 < 0)
            {
                break;
            }
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[p3] = nums1[p1--];
            }
            else
            {
                nums1[p3] = nums2[p2--];
            }
        }
    }
};
// time: O(m+n), space: O(1)