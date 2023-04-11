string removeStars(string s) 
    {
        stack<char>st;

        for(auto x:s)
        {
            if(x=='*')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(x);
            }
        }    

        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }