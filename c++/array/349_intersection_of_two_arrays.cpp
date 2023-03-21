// array: leetcode easy
/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> counter;
        vector<int> intersect;
        for (auto n1 : nums1)
        {
            counter.insert(n1);
        }
        for (auto n2 : nums2)
        {
            if (counter.count(n2))
            {
                intersect.push_back(n2);
                counter.erase(n2);
            }
        }
        return intersect;
    }
};
// both time and space: O(m+n)