// graph: leetcode medium
/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> borders;
        // step 1: border cells
        for (int r = 0; r < row; r++)
        {
            borders.push_back({r, 0});
            borders.push_back({r, col - 1});
        }
        for (int c = 0; c < col; c++)
        {
            borders.push_back({0, c});
            borders.push_back({row - 1, c});
        }
        // step 2: check each border cell + mark each escaped cell
        for (auto border : borders)
        {
            traverse(board, border[0], border[1]);
        }
        // step 3: re-fill in each cell: X stays X, O -> X, N -> O
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
                if (board[r][c] == 'N')
                {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void traverse(vector<vector<char>> &board, int r, int c)
    {
        // vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        if (board[r][c] != 'O')
            return;
        board[r][c] = 'N';
        int row = board.size();
        int col = board[0].size();
        if (c + 1 < col)
        {
            traverse(board, r, c + 1);
        }
        if (r + 1 < row)
        {
            traverse(board, r + 1, c);
        }
        if (c > 0)
        {
            traverse(board, r, c - 1);
        }
        if (r > 0)
        {
            traverse(board, r - 1, c);
        }
    }
};
// time: O(N) - worst case traverse each cell twice; space: O(N) - worst case N stack frames