// backtracking: leetcode medium
/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int row;
    int col;
    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[r][c] == word[0])
                {
                    if (backtracking(board, word, r, c, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool backtracking(vector<vector<char>> &board, string word, int r, int c, int index)
    {
        // base case where string and board is length 1
        if (index >= word.size())
        {
            return true;
        }
        // check boundary
        if (r < 0 || c < 0 || r >= row || c >= col || board[r][c] != word[index])
        {
            return false;
        }
        // if matches character, explore right, down, left, top for next character
        board[r][c] = '^';
        if (backtracking(board, word, r, c + 1, index + 1) ||
            backtracking(board, word, r + 1, c, index + 1) ||
            backtracking(board, word, r, c - 1, index + 1) ||
            backtracking(board, word, r - 1, c, index + 1))
        {
            return true;
        };
        // clean up and return result
        board[r][c] = word[index];
        return false;
    }
};
// Time: O(n x 3^l) -> n = # of cells, l = length of word, space : O(l)