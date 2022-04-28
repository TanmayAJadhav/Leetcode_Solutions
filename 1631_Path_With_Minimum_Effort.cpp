class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int res = 0;
        vector<vector<int>> temp = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        int total_row = heights.size();
        int total_col = heights[0].size();
        
        pq.push({0,0,0});
        
        while(pq.size())
        {
            auto node = pq.top();
            pq.pop();
            
            if(res < node[0])
            {
                res = node[0];
            }
            
            int row = node[1];
            int col = node[2];
            
            
            if((row == total_row - 1) && (col == total_col - 1))
            {
                break;
            }
            if(heights[row][col] != -1)
            {
                for(int i = 0; i < 4; i++)
                {
                    int newrow = row + temp[i][0];
                    int newcol = col + temp[i][1];

                    if((newrow >= 0) && (newcol >= 0) && (newrow != total_row) && (newcol != total_col)  && (heights[newrow][newcol] != -1))
                    {
                        pq.push({abs(heights[newrow][newcol]-heights[row][col]),newrow,newcol});
                    }
                }
            }
            
            heights[row][col] = -1;
        }
        return res;
    }
};