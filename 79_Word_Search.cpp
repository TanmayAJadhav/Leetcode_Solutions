class Solution {
public:
    bool solve(int i, int j, int index, vector<vector<char>>& board, string word)
    {
        if(index == word.size())
        {
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }

        bool ans = false;

        if(board[i][j] == word[index])
        {
            board[i][j] = '*';
            ans = solve(i+1,j,index+1,board,word) or 
                  solve(i,j+1,index+1,board,word) or
                  solve(i-1,j,index+1,board,word) or
                  solve(i,j-1,index+1,board,word);

            board[i][j] = word[index];    
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int index = 0;
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(word[index] == board[i][j])
                {
                    if(solve(i,j,index,board,word))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};79. Word Search