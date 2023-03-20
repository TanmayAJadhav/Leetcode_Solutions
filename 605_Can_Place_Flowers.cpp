class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        
        int cnt = 0, ans = 0, i = 0;
        if(i==0)
        {
            while(i<flowerbed.size() && flowerbed[i] == 0)
            {
                cnt++;
                i++;
            }
            if(cnt%2==1)
            {
                ans += ((cnt-1)/2);
            }
            else
            {
                ans += (cnt)/2;
            }
        }
        bool flag = true;
        cnt = 0;
        for(; i < flowerbed.size(); i++)
        {
            if(flowerbed[i] == 1)
            {
                flag = false;
                ans += ((cnt-1)/2);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        if(flowerbed[flowerbed.size()-1] == 0)
        {
            if(cnt%2==1)
            {
                ans += ((cnt-1)/2);
            }
            else
            {
                ans += (cnt)/2;
            }
        }
        cout<<"ans "<<ans<<endl;
        if(flag==true)
        {
            ans = (flowerbed.size()+1)/2;
        }
        if(ans >= n)
        {
            return true;
        }
        return false;
    }

};