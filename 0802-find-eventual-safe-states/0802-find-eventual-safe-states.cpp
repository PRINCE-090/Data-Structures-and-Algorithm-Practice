class Solution {
public:
   bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] = 0;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis,check) == true) return true;
        }
        else if(pathvis[it]) return true;
    }
    check[node] = 1;
    pathvis[node] = 0;
    return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
       vector<int>vis(n,0), pathvis(n,0), check(n,0);
       vector<int>safenode;

       for(int i = 0;i<n;i++){
           if(!vis[i]){
             dfs(i,adj,vis,pathvis,check);
            }
        }

        for(int i = 0;i<n;i++){
            if(check[i] == 1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};