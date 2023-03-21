// array: leetcode medium
/*
Return the maximum number of ice cream bars the boy can buy with coins coins.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

// counting sort
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int counts = 0;
        int max_cost = *max_element(costs.begin(), costs.end());
        vector<int> freq(max_cost + 1, 0); // index = cost
        for (auto c : costs)
        {
            freq[c]++;
        }
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 0)
            {
                continue;
            }
            else
            {
                if (freq[i] > coins)
                {
                    break;
                }
                // either able to buy all or portion
                int buy = min(freq[i], coins / i);
                counts += buy;
                coins -= buy * i;
            }
        }
        return counts;
    }
};
// time: O(n + m) - input array length + max element, space: O(m)