// binary, leetcode easy

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int counts = 0;
        while (n != 0)
        {
            if (n % 2 == 1)
            {
                counts++;
            }
            n = n >> 1;
        }
        return counts;
    }
};
// time: O(1), space: O(1)