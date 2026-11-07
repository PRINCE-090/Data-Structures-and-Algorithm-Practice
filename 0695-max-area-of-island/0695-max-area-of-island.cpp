class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] = 1;
        int area = grid[row][col];
        static const int x[4] = {-1,1,0,0};
        static const int y[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                area += dfs(nrow,ncol,grid,vis,n,m);
            }
        } 
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxarea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = dfs(i,j,grid,vis,n,m);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};