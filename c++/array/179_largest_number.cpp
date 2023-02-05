// array: leetcode medium
/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

bool comp(int num1, int num2)
{
    string temp1 = to_string(num1).append(to_string(num2));
    string temp2 = to_string(num2).append(to_string(num1));
    return temp1 > temp2;
};

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);
        string answer = "";
        for (auto n : nums)
        {
            answer.append(to_string(n));
        }
        return (answer[0] == '0' ? "0" : answer);
    }
};