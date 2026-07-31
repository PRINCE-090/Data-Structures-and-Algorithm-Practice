class Solution {
  public:
   void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
       vis[node] = 1;
       ans.push_back(node);
       for(auto it : adj[node]){
           if(vis[it] == 0){
               dfs(it,adj,vis,ans);
           }
       }
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
        return ans;
    }
};