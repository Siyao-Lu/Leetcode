// array: leetcode easy
/*
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one
row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
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
    vector<string> findWords(vector<string> &words)
    {
        vector<string> matches;
        unordered_map<char, int> counter;
        counter['q'] = 1;
        counter['w'] = 1;
        counter['e'] = 1;
        counter['r'] = 1;
        counter['t'] = 1;
        counter['y'] = 1;
        counter['u'] = 1;
        counter['i'] = 1;
        counter['o'] = 1;
        counter['p'] = 1;

        counter['a'] = 2;
        counter['s'] = 2;
        counter['d'] = 2;
        counter['f'] = 2;
        counter['g'] = 2;
        counter['h'] = 2;
        counter['j'] = 2;
        counter['k'] = 2;
        counter['l'] = 2;

        counter['z'] = 3;
        counter['x'] = 3;
        counter['c'] = 3;
        counter['v'] = 3;
        counter['b'] = 3;
        counter['n'] = 3;
        counter['m'] = 3;

        for (auto word : words)
        {
            bool same_line = true;
            int temp = counter[tolower(word[0])];
            for (int i = 1; i < word.size(); i++)
            {
                if (counter[tolower(word[i])] != temp)
                {
                    same_line = false;
                    break;
                }
            }
            if (same_line)
            {
                matches.push_back(word);
            }
        }
        return matches;
    }
};
// time: O(n*m) - iterating through each character in each word; space: O(1) limited number of characters need to store