// binary search: leetcode easy
/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target.
If such a character does not exist, return the first character in letters.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int size = letters.size();
        int left = 0, found = 0;
        int right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
            {
                found = mid;
                right = mid - 1;
            }
            else if (letters[mid] == target)
            {
                left = mid + 1;
            }
            else
            { // target is bigger
                left = mid + 1;
            }
        }
        return letters[found];
    }
};
// time: O(logn), space: O(1)