// array: leetcode medium (hash map)
/*
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
You may return the answer in any order.
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
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> sequences;
        set<string> checked;
        set<string> duplicates;
        if (s.size() < 10)
        {
            return sequences; // empty, less than 10
        }
        for (int i = 0; i < s.size() - 10; i++)
        {
            string temp = s.substr(i, 10);
            if (checked.count(temp) && !duplicates.count(temp))
            {
                // already exists
                sequences.push_back(temp);
                duplicates.insert(temp);
            }
            else
            {
                checked.insert(temp);
            }
        }
        return sequences;
    }
};
// time: O(n), space: O(n)