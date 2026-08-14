class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto [u,v] : pre){
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        if(q.empty()) return false;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo.size() == n;
    }
};