// stack and queue: leetcode easy
/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation
you must apply to the record and is one of the following:
Return the sum of all the scores on the record after applying all the operations.
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
    int calPoints(vector<string> &operations)
    {
        stack<int> scores;
        int temp = 0;
        int sum = 0;
        for (string operation : operations)
        {
            if (operation[0] == '-' || isdigit(operation[0]))
            {
                scores.push(stoi(operation));
            }
            else if (operation == "+")
            {
                temp = scores.top();
                scores.pop();
                sum = temp + scores.top();
                scores.push(temp);
                scores.push(sum);
            }
            else if (operation == "D")
            {
                temp = scores.top();
                scores.push(temp * 2);
            }
            else
            {
                scores.pop();
            }
        }
        sum = 0;
        while (!scores.empty())
        {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};