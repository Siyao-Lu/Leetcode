// binary search: leetcode medium
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        vector<int> columns;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        while (left <= right)
        { // start binary search
            int midIndex = (left + right) / 2;
            int midElement = matrix[midIndex / col][midIndex % col];
            if (midElement == target)
                return true;
            if (midElement < target)
            {
                left = midIndex + 1;
            }
            else
            {
                right = midIndex - 1;
            }
        }
        return false;
    }
};
// time: O(logmn), space: O(1)