// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its 
// eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

// Example 1:
// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

// Example 2:
// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]
 
// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.

class Solution
{
public:
    int countLives(vector<vector<int>> &board2, int i, int j, int rows, int cols)
    {
        int cnt = 0;
        if (i > 0)
        {
            if (board2[i - 1][j] == 1)
            {
                cnt++;
            }
        }

        if (j > 0)
        {
            if (board2[i][j - 1] == 1)
            {
                cnt++;
            }
        }

        if (i < rows - 1)
        {
            if (board2[i + 1][j] == 1)
            {
                cnt++;
            }
        }

        if (j < cols - 1)
        {
            if (board2[i][j + 1] == 1)
            {
                cnt++;
            }
        }

        if (i > 0 && j > 0)
        {
            if (board2[i - 1][j - 1] == 1)
            {
                cnt++;
            }
        }

        if (i < rows - 1 && j < cols - 1)
        {
            if (board2[i + 1][j + 1] == 1)
            {
                cnt++;
            }
        }

        if (i < rows - 1 && j > 0)
        {
            if (board2[i + 1][j - 1] == 1)
            {
                cnt++;
            }
        }

        if (i > 0 && j < cols - 1)
        {
            if (board2[i - 1][j + 1] == 1)
            {
                cnt++;
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>> &board)
    {

        vector<vector<int>> board2 = board;
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int cnt = countLives(board2, i, j, rows, cols);
                if (board[i][j] == 0)
                {
                    if (cnt == 3)
                    {
                        board[i][j] = 1;
                    }
                }
                else
                {
                    if (cnt < 2 || cnt > 3)
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};