class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 1)
        {
            return true;
        }
        if(n < 4)
        {
            return false;
        }
        int i = 2;
        while(i < 32)
        {
            long long int no = (1 << i);
            if(no == n)
            {
                return true;
            }
            else if(no > n)
            {
                return false;
            }
            i += 2;
        }
        
        return false;
    }
};