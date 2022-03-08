// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

// Example 1:
// Input: n = 234
// Output: 15 
// Explanation: 
// Product of digits = 2 * 3 * 4 = 24 
// Sum of digits = 2 + 3 + 4 = 9 
// Result = 24 - 9 = 15

class Solution {
public:
    int subtractProductAndSum(int no) {
     int digit = 0, result = 0, sum = 0, mul = 1;
        while(no != 0)
        {
            digit = no%10;
            sum = sum + digit;
            mul = mul * digit;
            no = no/10;
        }
        result = mul - sum;
        return result;
    }
};