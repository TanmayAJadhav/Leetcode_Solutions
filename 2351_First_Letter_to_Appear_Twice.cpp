class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>vec(26,false);

        for(auto x:s)
        {
            if(vec[x-'a']==true)
            {
                return x;
            }
            vec[x-'a']=true;
        }
        return 'a';
    }
};