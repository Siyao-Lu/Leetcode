// array: leetcode easy
/*
ou have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int possible = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                bool left = (i == 0) || flowerbed[i - 1] == 0;
                bool right = (i == flowerbed.size() - 1) || flowerbed[i + 1] == 0;
                if (left && right)
                {
                    possible++;
                    flowerbed[i] = 1;
                    if (possible >= n)
                        return true;
                }
            }
        }
        return false;
    }
};
// time: O(n), space: O(1)