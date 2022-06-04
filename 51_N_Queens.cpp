// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

// Constraints:
// 1 <= n <= 9

class Solution {
private:
    vector<vector<string>>ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(board,0,n);
        return ans;
    }
    
    void solve(vector<string>&board, int col, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(check(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(board, col+1, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool check(int row, int col, vector<string>&board, int n)
    {
        int copyrow = row, copycol = col;
        
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        
        row = copyrow, col = copycol;
        while((row >= 0) && (col >= 0))
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            col--;
            row--;
        }
        
        row = copyrow, col = copycol;
        while((row < n) && (col >= 0))
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }        
        
};