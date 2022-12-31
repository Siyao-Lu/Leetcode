// leetcode easy
/*
Design a class to find the kth largest element in a stream.
Note that it is the kth largest element in the sorted order,
not the kth distinct element.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq1; // min heap
    priority_queue<int, vector<int>, less<int>> pq2;    // max heap
    int size = 0;
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (auto num : nums)
        {
            if (pq1.size() < k)
            {
                pq1.push(num);
            }
            else
            {
                add(num);
            }
        }
    }

    int add(int val)
    {
        if (pq1.size() != size)
        {
            pq1.push(val);
        }
        else
        {
            int temp = pq1.top();
            if (temp < val)
            {
                pq1.pop();
                pq1.push(val);
                pq2.push(temp);
            }
            else
            {
                pq2.push(val);
            }
        }
        return pq1.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */