class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s = to_string(n);

        int len = s.size();
        int i;
        for(i = len-2; i >= 0; i--)
        {
            if(s[i] < s[i+1])
            {
                break;
            }
        }    

        if(i < 0)
        {
            return -1;
        }
        else
        {
            int j;
            for(j = len-1; j >= 0; j--)
            {
                if(s[i] < s[j])
                {
                    break;
                }
            }
            swap(s[i],s[j]);

            reverse(s.begin()+i+1,s.end());
        }
        long long num = stoll(s);
        if(num > INT_MAX)
        {
            return -1;
        }
        return num;
    }
};