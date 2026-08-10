class Solution {
public:
    bool bfs(int node,vector<vector<int>>&adj,vector<int>&color){
        color[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(bfs(i,graph,color) == false)
                return false;
            }
        }
      return true;

    }
};