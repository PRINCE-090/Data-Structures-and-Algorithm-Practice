class Solution {
  public:
  void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
      vis[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it,vis,adj);
          }
      }
  }
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        int cnt = 0;
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};