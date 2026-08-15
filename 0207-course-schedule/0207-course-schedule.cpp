class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>>adj(v);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(v,0);
        queue<int>q;
        vector<int>topo;
        for(int i = 0;i<v;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        if(q.empty()) return false;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo.size() == v;
    }
};

// using DFS
class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&status,int course){
      if(status[course] == 2) return true;
      if(status[course] == 1) return false;
      status[course] = 1;
      for(int next : adj[course]){
        if(!dfs(adj,status,next)) return false;
      }
      status[course] = 2;
      return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int>complete(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            if(!dfs(adj,complete,i)) return false;
        }
        return true;
    }
};
