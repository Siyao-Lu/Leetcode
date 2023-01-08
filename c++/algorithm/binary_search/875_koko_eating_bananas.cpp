// binary search: leetcode medium
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k
bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas
during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); // max eating speed k
        while (left < right)
        {
            int mid = (left + right) / 2;
            int hours = 0;
            for (int pile : piles)
            {
                hours += ceil((double)pile / (double)mid);
            }
            if (hours > h)
            {
                left = mid + 1;
            }
            else
            { // <=, but mid might not be the smallest eating speed
                right = mid;
            }
        }
        // two boundaries overlap: left=right
        return right;
    }
};
// space: O(1), time: O(NlogM) - n length of piles, m max bananas in a pile (1-M initial search space)