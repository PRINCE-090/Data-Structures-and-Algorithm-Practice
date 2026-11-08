class Solution {
public:
    long long dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] = 1;
        long long totalvalue = grid[row][col];
        static const int x[4] = {-1,1,0,0};
        static const int y[4] = {0,0,1,-1};
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != 0 && !vis[nrow][ncol]){
                totalvalue += dfs(nrow,ncol,grid,vis,n,m);
            }
        }
        return totalvalue;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt  = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    long long island = dfs(i,j,grid,vis,n,m);
                    if(island % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};