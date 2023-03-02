class Solution {
public:
    int totalMoney(int n) 
    {
        int ans = 0;
        int sumtillseven = 28;
        int divide = n/7;
        int intosumtillseven = 28*divide;
        int modrem = n%7;

        ans += intosumtillseven + ((modrem*(modrem+1))/2);
        int otherdivide = (n/7);
        int othermod = n%7;

        ans += 7*(otherdivide*(otherdivide+1)/2);
        ans -= ((7-othermod)*otherdivide);
        return ans;

    }
};