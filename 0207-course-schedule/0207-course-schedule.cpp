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