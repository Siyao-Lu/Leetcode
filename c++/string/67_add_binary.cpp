// string: leetcode easy
/*
Given two binary strings a and b, return their sum as a binary string.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string sum = "";
        bool carry = false;
        int size = (a.size() > b.size()) ? b.size() : a.size();
        for (int i = 0; i < size; i++)
        {
            if ((a[a.size() - 1 - i] - '0') + (b[b.size() - 1 - i] - '0') == 0)
            {
                if (carry)
                {
                    sum = "1" + sum;
                    carry = false;
                }
                else
                {
                    sum = "0" + sum;
                }
            }
            else if ((a[a.size() - 1 - i] - '0') + (b[b.size() - 1 - i] - '0') == 1)
            {
                if (carry)
                {
                    sum = "0" + sum;
                }
                else
                {
                    sum = "1" + sum;
                }
            }
            else
            { // 2
                if (carry)
                {
                    sum = "1" + sum;
                }
                else
                {
                    sum = "0" + sum;
                    carry = true;
                }
            }
        }
        if (a.size() != b.size())
        {
            int remaining = 0;
            if (a.size() > b.size())
            {
                remaining = a.size() - b.size();
                for (int i = remaining - 1; i >= 0; i--)
                {
                    if (a[i] == '1')
                    {
                        if (carry)
                        {
                            sum = "0" + sum;
                        }
                        else
                        {
                            sum = "1" + sum;
                        }
                    }
                    else
                    {
                        if (carry)
                        {
                            sum = "1" + sum;
                            carry = false;
                        }
                        else
                        {
                            sum = "0" + sum;
                        }
                    }
                }
            }
            else
            {
                remaining = b.size() - a.size();
                for (int i = remaining - 1; i >= 0; i--)
                {
                    if (b[i] == '1')
                    {
                        if (carry)
                        {
                            sum = "0" + sum;
                        }
                        else
                        {
                            sum = "1" + sum;
                        }
                    }
                    else
                    {
                        if (carry)
                        {
                            sum = "1" + sum;
                            carry = false;
                        }
                        else
                        {
                            sum = "0" + sum;
                        }
                    }
                }
            }
            if (carry)
            {
                sum = "1" + sum;
            }
            return sum;
        }
        else
        {
            if (carry)
            {
                sum = "1" + sum;
            }
            return sum;
        }
    }
};
// time: O(max(N,M)), space: O(max(N,M))