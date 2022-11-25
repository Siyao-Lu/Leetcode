// leetcode medium
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;
class Solution
{
public:
    struct greater
    {
        bool operator()(const pair<int, int> &pair1, const pair<int, int> &pair2)
        {
            return pair1.second > pair1.first;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;
        vector<int> frequent;
        unordered_map<int, int> counter;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater> pq;
        for (auto num : nums)
        {
            counter[num]++;
        }
        for (auto pair : counter)
        {
            pq.push(pair);
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            frequent.push_back(pq.top().first);
            pq.pop();
        }
        return frequent;
    }
};