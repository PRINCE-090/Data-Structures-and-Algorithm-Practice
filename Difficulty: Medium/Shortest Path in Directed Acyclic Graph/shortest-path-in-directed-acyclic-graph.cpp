class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(V,1e9);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int val = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int weight = it.second;
                int adjnode = it.first;
                if(val + weight < dist[adjnode]){
                    dist[adjnode] = val+weight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        vector<int>ans;
        for(auto it : dist){
            if(it == 1e9) ans.push_back(-1);
            else ans.push_back(it);
        }
        return ans;
    }
};
