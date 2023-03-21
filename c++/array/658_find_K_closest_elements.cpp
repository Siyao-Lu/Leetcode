// array: leetcode medium; Binary search to find leftmost index
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.
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
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int size = arr.size();
        if (size < k)
            return {};
        int left = 0;
        int right = size - k; // assume right is the starting index, the most it can start is size - k
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (x - arr[mid] <= arr[mid + k] - x)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        vector<int> closestK;
        for (int i = left; i < left + k; i++)
        {
            closestK.push_back(arr[i]);
        }
        return closestK;
    }
};
// time: O(log(N−k)+k); space: O(1)