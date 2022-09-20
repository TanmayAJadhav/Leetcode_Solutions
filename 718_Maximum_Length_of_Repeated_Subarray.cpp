class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int n1 = A.size(), n2 = B.size(), ans = 0;

        for (int i = -n1 + 1; i < n1; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n2; ++j)
            {
                if ((i + j) < 0)
                {
                    continue;
                }
                else if ((i + j) >= n1)
                {
                    break;
                }
                else if (A[i + j] == B[j])
                {
                    cnt++;
                    ans = max(ans, cnt);
                }
                else
                {
                    cnt = 0;
                }
            }
        }

        return ans;
    }
};