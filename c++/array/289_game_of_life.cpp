// array: leetcode easy
/*
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
Given the current state of the m x n grid board, return the next state.
*/
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <array>
using namespace std;

/*
0: original state dead, nect state dead
1: original state alive, next state alive
2: original state dead, next state alive
3: original state alive, next state dead

modify board in-place
*/
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        int R = board.size();
        int C = board[0].size();
        for (int row = 0; row < R; row++)
        {
            for (int col = 0; col < C; col++)
            {
                int n = 0;
                for (auto d : directions)
                {
                    if (row + d[0] >= 0 && row + d[0] < R && col + d[1] >= 0 && col + d[1] < C)
                    {
                        if (board[row + d[0]][col + d[1]] % 2 == 1)
                        {
                            n++;
                        }
                    }
                }
                // rule 1 & 3
                if (board[row][col] % 2 == 1 && (n < 2 || n > 3))
                {
                    board[row][col] = 3;
                }
                // rule 4
                else if (board[row][col] % 2 == 0 && n == 3)
                {
                    board[row][col] = 2;
                }
            }
        }
        for (int row = 0; row < R; row++)
        {
            for (int col = 0; col < C; col++)
            {
                if (board[row][col] == 3 || board[row][col] == 2)
                {
                    board[row][col] = (board[row][col] - 1) % 2;
                }
            }
        }
    }
};
// time: O(mn), space: O(1)