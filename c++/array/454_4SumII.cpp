// array: leetcode medium
/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> counter;
        int counts = 0;
        for (auto n1 : nums1)
        {
            for (auto n2 : nums2)
            {
                counter[n1 + n2]++;
            }
        }
        // check sum complement in nums3 and nums4
        for (auto n3 : nums3)
        {
            for (auto n4 : nums4)
            {
                int temp = -(n3 + n4);
                if (counter.count(temp))
                {
                    counts += counter[temp];
                }
            }
        }
        return counts;
    }
};
// time: O(n^2), space: O(n^2)