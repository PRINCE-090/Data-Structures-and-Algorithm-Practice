class Solution {
  public:
    bool bfs(int idx,vector<vector<int>>&adj,vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({idx,-1});
        vis[idx] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else{
                    if(it != parent) return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++){
            int src = edges[i][0];
            int des = edges[i][1];
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
       vector<int>vis(V);
       for(int i = 0;i<V;i++){
           if(!vis[i]){
               if(bfs(i,adj,vis)) return true;
           }
       }
       return false;
       
    } 
};