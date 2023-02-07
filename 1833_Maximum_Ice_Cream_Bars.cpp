class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0,totalcoins = 0;
        sort(costs.begin(),costs.end());

        for(auto x:costs)
        {
            if(totalcoins+x > coins)
            {
                break;
            }
            totalcoins += x;
            ans++;
        }

        return ans;
    }
};