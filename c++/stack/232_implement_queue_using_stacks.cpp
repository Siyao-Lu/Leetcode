// stack and queue: leetcode easy
/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/

#include <algorithm>
#include <stack>
using namespace std;

// stack first in last out, queue first in first out
class MyQueue
{
public:
    stack<int> front;
    stack<int> back;
    MyQueue()
    {
    }

    void push(int x)
    {
        front.push(x);
    }

    int pop()
    {
        if (back.empty())
        {
            while (!front.empty())
            {
                back.push(front.top());
                front.pop();
            }
        }
        int target = back.top();
        back.pop();
        return target;
    }

    int peek()
    {
        if (back.empty())
        {
            while (!front.empty())
            {
                back.push(front.top());
                front.pop();
            }
        }
        return back.top();
    }

    bool empty()
    {
        return (front.empty() && back.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
