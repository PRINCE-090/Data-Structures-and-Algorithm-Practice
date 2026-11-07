class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] = 1;
        static const int x[4] = {-1,1,0,0};
        static const int y[4] = {0,0,-1,1};
        int maxfish = grid[row][col];
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]!= 0){
               maxfish +=  dfs(nrow,ncol,grid,vis,n,m);
            }
        }
        return maxfish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxfish = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(grid[i][j] != 0 && !vis[i][j]){
                int fishcount = dfs(i,j,grid,vis,n,m);
                maxfish = max(maxfish,fishcount);
               }
            }
        }
        return maxfish;
    }
};