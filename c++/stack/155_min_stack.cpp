// stack and queue: leetcode medium
/*
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// queue first in first out, stack first in last out
class MinStack
{
public:
    stack<int> *ptr;
    int min_val = INT_MAX;
    vector<int> *track;
    MinStack()
    {
        ptr = new stack<int>;
        track = new vector<int>;
    }

    void push(int val)
    {
        ptr->push(val);
        track->push_back(val);
        min_val = (val < min_val) ? val : min_val;
    }

    void pop()
    {
        int target = ptr->top();
        ptr->pop();
        track->erase(find(track->begin(), track->end(), target));
        if (ptr->empty())
        {
            min_val = INT_MAX;
        }
        else
        {
            if (target == min_val)
            {
                sort(track->begin(), track->end());
                min_val = track->at(0);
            }
        }
    }

    int top()
    {
        return ptr->top();
    }

    int getMin()
    {
        return min_val;
    }
};
// time: O(1), space: O(n); better implementation with 2 stacks (regular and minStack, adding to minStack if val is <= minStack top)
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */