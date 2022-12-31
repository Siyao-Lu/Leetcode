// array: leetcode medium
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
validated according to the following rules:
*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<int> row;
        vector<set<int>> col(9);
        vector<set<int>> square(3);
        /*
        1. By row
        2. By col
        3. By each 3x3
        */
        for (int r = 0; r < 9; r++)
        {
            if (r % 3 == 0 && r != 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    square[i].clear();
                }
            }
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    int element = board[r][c] - '0';
                    if (row.count(element) || col[c].count(element) || square[c / 3].count(element))
                    {
                        return false;
                    }
                    row.insert(element);
                    col[c].insert(element);
                    square[c / 3].insert(element);
                }
            }
            row.clear();
        }
        return true;
    }
};
// time: O(n^2), space: O(n^2)