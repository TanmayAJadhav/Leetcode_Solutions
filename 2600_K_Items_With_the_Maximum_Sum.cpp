class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        if(k <=  numOnes+numZeros)
        {
            return min(k,numOnes);
        }
        int rem = k-(numOnes+numZeros);

        return numOnes - rem;        
    }
};