class Solution {
public:
    bool isvalid(int nrow,int ncol,int n,int m){
        if( nrow >= 0 && nrow < n &&  ncol >= 0 && ncol < m ) return true;
        return false;
    }
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
      vis[row][col] = 1;
      int x[4] = {-1,1,0,0};
      int y[4] = {0,0,-1,1};
      for(int i = 0;i<4;i++){
        int nrow = row + x[i];
        int ncol = col + y[i];
        if(isvalid(nrow,ncol,n,m) && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
            dfs(nrow,ncol,grid,vis,n,m);
        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};