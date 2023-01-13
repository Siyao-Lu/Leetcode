// stack: leetcode medium
/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction
(positive meaning right, negative meaning left).
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode.
Two asteroids moving in the same direction will never meet.
*/

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// A collision will only happen if a negative number is coming after positive and not vice-versa
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        if (asteroids.empty() || asteroids.size() == 1)
        {
            return asteroids;
        }
        stack<int> asts;
        for (int ast : asteroids)
        {
            if (asts.empty())
            {
                asts.push(ast);
            }
            else
            {
                int temp = asts.top();
                if ((temp > 0 && ast > 0) || (temp < 0 && ast < 0))
                {
                    asts.push(ast);
                }
                else
                { // different sign
                    asts.pop();
                    if (ast < 0 && temp > 0)
                    {
                        if (temp + ast != 0)
                        {
                            abs(temp) > abs(ast) ? asts.push(temp) : asts.push(ast);
                        }
                        while (asts.size() >= 2)
                        {
                            int first = asts.top();
                            asts.pop();
                            int second = asts.top();
                            asts.pop();
                            if ((first > 0 && second > 0) || (first < 0 && second < 0))
                            {
                                asts.push(second);
                                asts.push(first);
                                break;
                            }
                            else
                            {
                                if (second > 0 && first < 0)
                                {
                                    if (first + second != 0)
                                    {
                                        abs(first) > abs(second) ? asts.push(first) : asts.push(second);
                                    }
                                }
                                else
                                {
                                    asts.push(second);
                                    asts.push(first);
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        asts.push(temp);
                        asts.push(ast);
                    }
                }
            }
        }
        vector<int> results(asts.size(), 0);
        for (int i = asts.size() - 1; i >= 0; i--)
        {
            results[i] = asts.top();
            asts.pop();
        }
        return results;
    }
};
// time: O(n), space: O(n)