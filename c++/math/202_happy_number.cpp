// math: leetcode easy
/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// this is an implict linked list cycle problem => Floyd's Tortoise and Hare algorithm
class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        do
        {
            slow = next(slow);
            fast = next(next(fast));

        } while (slow != fast && fast != 1);
        return (fast == 1);
    }

private:
    int next(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            int temp = num % 10;
            num /= 10;
            sum += pow(temp, 2);
        }
        return sum;
    }
};
// time: O(logn), space: O(1)