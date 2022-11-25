// array: leetcode easy (Blind 75 LeetCode Questions)
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        class Solution
        {
        public:
            vector<int> twoSum(vector<int> &nums, int target)
            {
                vector<int> solution;
                for (int i = 0; i < nums.size(); i++)
                {
                    int other = target - nums[i];
                    // the other pair exists and is not itself
                    if (find(nums.begin(), nums.end(), other) != nums.end() &&
                        (find(nums.begin(), nums.end(), other) - nums.begin() != i))
                    {
                        int index = find(nums.begin(), nums.end(), other) - nums.begin();
                        solution.push_back(i);
                        solution.push_back(index);
                        break;
                    }
                }
                return solution;
            }
        };
    }
}; // my solution, 191ms runtime
   // space complexity: O(n)
   // time complexity: O(n) => one pass

// optimized solution: one map pass ~30ms runtime
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> solution(2, 0);
//         map<int, int> store;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int complement = target - nums[i];
//             if (store.find(complement) != store.end())
//             {
//                 solution[0] = i;
//                 solution[1] = store[complement];
//                 break;
//             }
//             store[nums[i]] = i;
//         }
//         return solution;
//     }
// };