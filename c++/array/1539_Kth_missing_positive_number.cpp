// array: leetcode easy
/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*
with binary search:
arr[i]−(i+1) gives the number of missing integers before index i

arr[start−1]−((start−1)+1) gives the number of missing integers before index start−1start - 1start−1
*/
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int size = arr.size();
        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] - (mid + 1) < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left + k;
    }
};
// time: O(logn), space: O(1)