class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> decoded;
        int ans = first;
        decoded.push_back(ans);
        for(int i = 0; i < encoded.size(); i++)
        {
            ans = ans ^ encoded[i];
            decoded.push_back(ans);
        }
        return decoded;
    }
};