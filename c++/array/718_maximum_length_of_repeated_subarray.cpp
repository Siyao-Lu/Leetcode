// array: leetcode medium; sliding window
/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
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
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n1_size = nums1.size();
        int n2_size = nums2.size();
        int max_counts = 0;
        for (int i = 0; i < n1_size + n2_size; i++)
        {
            int n1 = max(0, n1_size - 1 - i); // nums1 loop back from the back
            int n2 = max(0, i - n1_size + 1); // nums2 loop back from the beginning
            int counts = 0;
            while (n1 < n1_size && n2 < n2_size)
            {
                if (nums1[n1] == nums2[n2])
                {
                    counts++;
                    max_counts = max(max_counts, counts);
                }
                else
                {
                    counts = 0;
                }
                n1++;
                n2++;
            }
        }
        return max_counts;
    }
};