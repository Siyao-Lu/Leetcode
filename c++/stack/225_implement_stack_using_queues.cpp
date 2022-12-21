// stack and queue: leetcode easy
/*
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/

#include <algorithm>
#include <queue>
using namespace std;

// queue first in first out, stack first in last out
class MyStack
{
public:
    queue<int> *front;
    queue<int> *back;
    int val;
    MyStack()
    {
        front = new queue<int>;
        back = new queue<int>;
    }

    void push(int x)
    {
        front->push(x);
    }

    int pop()
    {
        if (front->empty())
        {
            while (!back->empty())
            {
                val = back->front();
                back->pop();
                if (!back->empty())
                {
                    front->push(val);
                }
            }
        }
        else
        {
            while (!front->empty())
            {
                val = front->front();
                front->pop();
                if (!front->empty())
                {
                    back->push(val);
                }
            }
        }
        return val;
    }

    int top()
    {
        if (front->empty())
        {
            while (!back->empty())
            {
                val = back->front();
                back->pop();
                front->push(val);
            }
        }
        else
        {
            while (!front->empty())
            {
                val = front->front();
                front->pop();
                back->push(val);
            }
        }
        return val;
    }

    bool empty()
    {
        return (front->empty() && back->empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */