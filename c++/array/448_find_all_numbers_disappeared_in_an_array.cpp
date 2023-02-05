// array: leetcode easy
/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
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
    vector<int> disappeared;
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        /*
        sort
        case 1: beginning (must be 1 if all in)
        case 2: end
        case 3: middle (must be nums.size() if all in)
        */
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                if (nums[i] != 1)
                {
                    add(0, nums[i]);
                }
            }
            else
            {
                if ((nums[i] != nums[i - 1]) && (nums[i - 1] + 1 != nums[i]))
                {
                    add(nums[i - 1], nums[i]);
                }
            }
        }
        // check end
        add(nums[size - 1], size + 1); // exclusive begin and end
        return disappeared;
    }

private:
    void add(int begin, int end)
    {
        while (begin < end)
        {
            begin++;
            disappeared.push_back(begin);
        }
    }
};