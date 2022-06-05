// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

// Example 2:
// Input: n = 1
// Output: 1
 
// Constraints:
// 1 <= n <= 9

class Solution {
private:
    int ans = 0;
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        solve(board,0,n);
        return ans;
    }
    
    void solve(vector<vector<int>>&board, int col, int n)
    {
        if(col == n)
        {
            ans++;
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(check(row, col, board, n))
            {
                board[row][col] = 1;
                solve(board, col+1, n);
                board[row][col] = 0;
            }
        }
    }
    
    bool check(int row, int col, vector<vector<int>>&board, int n)
    {
        int copyrow = row, copycol = col;
        
        while(col >= 0)
        {
            if(board[row][col] == 1)
            {
                return false;
            }
            col--;
        }
        
        row = copyrow, col = copycol;
        while((row >= 0) && (col >= 0))
        {
            if(board[row][col] == 1)
            {
                return false;
            }
            col--;
            row--;
        }
        
        row = copyrow, col = copycol;
        while((row < n) && (col >= 0))
        {
            if(board[row][col] == 1)
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }        
};