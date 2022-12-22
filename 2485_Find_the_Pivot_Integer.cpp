class Solution {
public:
    int pivotInteger(int n) {
        long long int totalsum = (n*(n+1))/2;
        long long int sum = 0;
        vector<int>vec(n+1);

        for(int i = 1; i <= n; ++i)
        {
            sum += i;
            vec[i] = sum;
            if(sum >= totalsum/2)
            {
                if(sum + vec[i-1] == totalsum)
                {
                    return i;
                }
                else
                {
                    return -1;
                }
                break;
            }
        }        
        return -1;
    }
};