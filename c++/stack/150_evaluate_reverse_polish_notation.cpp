// stack: leetcode medium
/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> operands;
        int first;
        int second;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                first = operands.top();
                operands.pop();
                second = operands.top();
                operands.pop();
                if (token == "+")
                {
                    operands.push(first + second);
                }
                else if (token == "-")
                {
                    operands.push(second - first);
                }
                else if (token == "*")
                {
                    operands.push(second * first);
                }
                else
                {
                    operands.push(second / first);
                }
            }
            else
            { // numbers
                operands.push(stoi(token));
            }
        }
        return (operands.size() == 1) ? operands.top() : -1;
    }
};
// time: O(n), space: O(N)