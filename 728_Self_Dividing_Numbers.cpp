// A self-dividing number is a number that is divisible by every digit it contains.For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.A self-dividing number is not allowed to contain the digit zero.Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

// Example 1:
// Input: left = 1, right = 22
// Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

// Example 2:
// Input: left = 47, right = 85
// Output: [48,55,66,77]

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int leftnum = left; leftnum <= right; ++leftnum)
        {
            int digit = 0;
            int copy = leftnum;
            if(leftnum%10==0)
            {
                continue;
            }
            while(copy != 0)
            {
                digit = copy%10;
                if((digit == 0) || (leftnum%digit != 0))
                {
                    break;
                }
                copy = copy/10;
            }
            if(copy==0)
            {
                ans.push_back(leftnum);
            }
        }
        return ans;
    }
};