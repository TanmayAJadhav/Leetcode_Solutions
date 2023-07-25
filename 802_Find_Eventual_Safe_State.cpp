class Solution {
public:
    void checkthis(int node, vector<vector<int>>&adj, vector<int>&vis)
    {
        vis[node] = 2;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                checkthis(child,adj,vis);
            }
            if(vis[child] == 2)
            {
                return;
            }
            
        }

        vis[node] = 1;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int>vis(V,0);

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                checkthis(i,graph,vis);
            }
        }
       
        vector<int>ans;
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};