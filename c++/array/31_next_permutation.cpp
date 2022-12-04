// array: leetcode medium
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

class Solution
{
public:
    void swap(vector<int> &nums, int index)
    {
        int num = nums[index];
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
            {
                nums[index] = nums[i];
                nums[i] = num;
                break;
            }
            else if (nums[i] > num && nums[i + 1] <= num)
            {
                nums[index] = nums[i];
                nums[i] = num;
                break;
            }
        }
    };

    void reverse(vector<int> &nums, int index)
    {
        int left = index;
        int right = nums.size() - 1;
        while (left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    };

    void nextPermutation(vector<int> &nums)
    {
        int target = -1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                swap(nums, i - 1); // choose the next minimum to swap with
                target = i;
                break;
            }
        }
        if (target != -1)
        {
            reverse(nums, target); // after swap, to the right is in strict descending order, reverse it
        }
        else
        {
            // no match => vector is in strict descending order => simply reverse the vector
            reverse(nums, 0);
        }
    }
};
// time: O(n), space: O(1)