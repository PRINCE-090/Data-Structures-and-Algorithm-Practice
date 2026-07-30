class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int>q;
        vector<int>ans;
        int n = adj.size();
       vector<int>vis(n+1,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for(auto it : adj[val]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};