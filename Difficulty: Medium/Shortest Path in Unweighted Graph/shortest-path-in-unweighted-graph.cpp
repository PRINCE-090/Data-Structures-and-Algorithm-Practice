class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        vector<int>dist(V,1e9);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i = 0;i<dist.size();i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans[dest];
    }
};
