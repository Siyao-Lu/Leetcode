// array: leetcode medium (extension of 2sum & 3sum)
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> solution(2, 0);
        for (int i = 0; i < numbers.size(); i++)
        {
            if (i == 0 || numbers[i] != numbers[i - 1])
            {
                int potential = numbers.size() - 1;
                while (potential > i)
                {
                    if (numbers[i] + numbers[potential] == target)
                    {
                        solution[0] = i + 1;
                        solution[1] = potential + 1;
                        return solution;
                    }
                    else if (numbers[i] + numbers[potential] < target)
                    {
                        break;
                    }
                    potential--;
                }
            }
        }
        return solution;
    }
};
// time: O(n), space O(1)

/*
sample faster implementation
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while(left < right)
        {
            int sum = numbers[left]+numbers[right];
            if(sum == target) return {left+1, right+1};
            else if (sum < target) left++;
            else right--;
        }

        return {};
    }
};
*/