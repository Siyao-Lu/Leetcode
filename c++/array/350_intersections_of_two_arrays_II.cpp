// array: leetcode easy
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times
as it shows in both arrays and you may return the result in any order.
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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> counter;
        vector<int> results;
        for (auto num : nums1)
        {
            counter[num]++;
        }
        for (auto num : nums2)
        {
            if (counter.count(num))
            {
                results.push_back(num);
                if (counter[num] > 1)
                {
                    counter[num]--;
                }
                else
                {
                    counter.erase(num);
                }
            }
        }
        return results;
    }
};
// time: O(n), space: O(n)