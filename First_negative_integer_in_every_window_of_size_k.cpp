vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    deque<long long>dq;
    vector<long long>ans;
    
    for(int i = 0; i < K; i++)
    {
        if(A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    
    for(long long i = K; i < N; i++)
    {
        if(dq.empty()==true)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[dq.front()]);
        }
        
        while(!dq.empty() && dq.front() <= i-K)
        {
            dq.pop_front();
        }
        
        if(A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    
    if(dq.empty()==true)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[dq.front()]);
    }
    return ans;
}