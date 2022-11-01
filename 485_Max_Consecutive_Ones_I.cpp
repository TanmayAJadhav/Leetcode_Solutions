class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,ans = 0;
        int cntone = 0;
        if(nums.size()==1 && nums[0] == 0)
        {
            return 0;
        }   
        if(nums[0]==0 && nums[1]==1 && nums.size()==2)
        {
            return 1;
        } 
        while((j < nums.size()-1) && (nums[j]==1))
        {
            cntone++;
            j++;
        }
        if(nums[cntone]==1)
        {
            cntone++;
        }
        ans = max((j-i),ans);
            i = j;
            j++; 
        cout<<"this is i "<<i<<" "<<j<<" "<<cntone<<endl;    
        if(cntone == nums.size())
        {
            return nums.size();
        }
        while(j < nums.size()-1)
        {
            while((j < nums.size()-1) && nums[j]==1 && (nums[j] == nums[j+1]))
            {
                j++;
            }
            ans = max((j-i),ans);
            i = j;
            j++;
        }
        return ans;
        
    }
};