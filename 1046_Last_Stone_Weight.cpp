class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int x:stones)
        {
            q.push(x);
        }
        while(q.size() > 1)
        {
            int one = q.top();
            q.pop();
            int two = q.top();
            q.pop();

            if(one == two)
            {
                continue;
            }
            else 
            {
                q.push(abs(one-two));
            }
        }
        if(q.size()==0)
        {
            return 0;
        }
        return q.top();
    }
};