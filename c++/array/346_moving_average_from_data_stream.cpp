// array: leetcode easy
/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class MovingAverage
{
public:
    int maxSize;
    queue<int> q;
    int total = 0;
    MovingAverage(int size)
    {
        maxSize = size;
    }

    double next(int val)
    {
        if (q.size() < maxSize)
        {
            q.push(val);
            total += val;
        }
        else
        {
            total -= q.front();
            q.pop();
            q.push(val);
            total += val;
        }
        return total / (double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */