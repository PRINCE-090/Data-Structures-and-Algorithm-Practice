class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
           int  steps = pq.top().first;
            pq.pop();
             
             if(steps > dist[node]) continue;

            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgeW = it.second;

                if(edgeW + steps < dist[adjnode]){
                  dist[adjnode] = edgeW + steps;
                pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int mindistance = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            mindistance = max(mindistance,dist[i]);
        }
        return mindistance;
    }
};