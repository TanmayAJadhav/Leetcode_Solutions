class Solution {
public:
    string predictPartyVictory(string senate)
    {
        queue<int>radiant,dire;
        int n = senate.size();

        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
            {
                radiant.push(i);
            }
            else
            {
                dire.push(i);
            }
        }

        while(!radiant.empty() && !dire.empty())
        {
            if(radiant.front() < dire.front())
            {
                int pos = radiant.front();
                radiant.pop();
                dire.pop();
                radiant.push(pos+n);
            }
            else
            {
                int pos = dire.front();
                radiant.pop();
                dire.pop();
                dire.push(pos+n);
            }
        }

        if(radiant.size()==0)
        {
            return "Dire";
        }
        return "Radiant";
    }
};