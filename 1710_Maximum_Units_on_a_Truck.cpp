class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); i++)
        {
            if(boxTypes[i][0] >= truckSize)
            {
                ans += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            else
            {
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][1]*boxTypes[i][0];
            }
        }
        
        return ans;
    }
};