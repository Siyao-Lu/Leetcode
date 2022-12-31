// leetcode heap medium
/*
Given a characters array tasks, representing the tasks a CPU needs to do,
where each letter represents a different task. Tasks could be done in any order.
Each task is done in one unit of time. For each unit of time, the CPU could complete
either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between
two same tasks (the same letter in the array), that is that there must be at least n units
of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int totalTime = 0;
        int cycle = n + 1;
        unordered_map<char, int> counts;
        vector<int> temp;
        priority_queue<int> pq; // default max heap (in descending order)
        for (auto task : tasks)
        {
            counts[task]++;
        }
        for (auto count : counts)
        {
            pq.push(count.second);
        }
        while (!pq.empty())
        { // controlled by  max freq of any character
            int time = 0;
            for (int i = 0; i < cycle; i++)
            {
                if (!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto t : temp)
            {
                if (--t)
                {
                    pq.push(t);
                }
            }
            temp.clear();
            totalTime += !pq.empty() ? cycle : time;
        }
        return totalTime;
    }
};
// time: O(n), space: O(1) ? - max 26 characters...