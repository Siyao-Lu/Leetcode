// math: leetcode medium
/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // main difficulty: check if reversed int out of bound
        int reverse = 0;
        while (x != 0)
        {
            int tail = x % 10;
            if (reverse > 0)
            {
                if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && tail > INT_MAX % 10))
                {
                    return 0;
                }
            }
            else
            {
                if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && tail < INT_MIN % 10))
                {
                    return 0;
                }
            }
            reverse = reverse * 10 + tail;
            x /= 10;
        }
        return reverse;
    }
};
// time: O(logn), space: O(1)

// int reverse = 0;
// while (x != 0)
// {
//     int tail = x % 10;
//     int temp = reverse * 10 + tail; // if out of bound, it will wrap around
//     if (temp / 10 != reverse)
//     {
//         return 0;
//     }
//     reverse = temp;
//     x = x / 10;
// }
// return reverse;