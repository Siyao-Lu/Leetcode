// binary search: leetcode easy
/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 0;
        int right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == -1)
            { // too high
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1; // paceholder, will always find answer
    }
};
// time: O(logn), space: O(1)