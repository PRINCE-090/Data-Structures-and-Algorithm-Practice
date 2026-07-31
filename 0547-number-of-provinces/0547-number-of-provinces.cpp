class Solution {
public:
    void dfs(int node,vector<vector<int>>&arr,vector<int>&vis){
        vis[node] = 1;
       for(int i = 0;i<arr.size();i++){
        if(arr[node][i] == 1 && !vis[i]){
            dfs(i,arr,vis);
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       vector<int>vis(n+1,0);
       int cnt = 0;
       for(int i = 0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,isConnected,vis);
        }
       }
       return cnt;
    }
};