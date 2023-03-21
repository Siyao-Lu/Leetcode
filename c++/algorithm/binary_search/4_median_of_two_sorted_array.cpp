// binary search: leetcode hard
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 == 0 && size2 == 0)
        {
            return 0.0;
        }
        if (size1 == 0)
        {
            int mid = (size2 - 1) / 2;
            return (size2 % 2 == 0) ? (nums2[mid] + nums2[mid + 1]) / 2 : nums2[mid];
        }
        if (size2 == 0)
        {
            int mid = (size1 - 1) / 2;
            return (size1 % 2 == 0) ? (nums1[mid] + nums1[mid + 1]) / 2 : nums1[mid];
        }
        vector<int> A, B;
        A = (size1 < size2) ? nums1 : nums2;
        B = (size1 < size2) ? nums2 : nums1;
        int total = size1 + size2;
        int left = 0;
        int right = A.size() - 1;
        double result = 0.0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // A: left - mid
            int index = (total + 1) / 2 - mid;   //  potential B starting point
            int A_left = (mid >= 0) ? A[mid] : INT_MIN;
            int A_right = (mid + 1 < A.size()) ? A[mid + 1] : INT_MAX;
            int B_left = (index >= 0) ? B[index] : INT_MIN;
            int B_right = (index + 1 < B.size()) ? B[index + 1] : INT_MAX;

            // correct partition
            if (A_left <= B_right && B_left <= A_right)
            {
                result = (total % 2 == 0) ? (max(A_left, B_left) + min(A_right, B_right)) / 2 : min(A_right, B_right);
                break;
            }
            else if (A_left > B_right)
            {
                // less A, more B
                right = mid - 1;
            }
            else
            {
                // more A, less B
                left = mid + 1;
            }
        }
        return result;
    }
};