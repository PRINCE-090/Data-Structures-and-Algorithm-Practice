class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col,int intial,int color,int n,int m, vector<vector<bool>>&vis){
        vis[row][col] = true;
        bool isborder = false;
        const static int x[4] = {-1,1,0,0};
        const static int y[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];
            if(nrow < 0 || nrow >= n  || ncol < 0 || ncol >= m ){
                isborder  = true;
            }
            else if(!vis[nrow][ncol] && grid[nrow][ncol] != intial){
                isborder = true;
            }
            else if(!vis[nrow][ncol] && grid[nrow][ncol] == intial){
                dfs(grid,nrow,ncol,intial,color,n,m,vis);
            }
        }
        if(isborder){
            grid[row][col] = color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int intial = grid[row][col];
        if(intial == color) return grid;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        dfs(grid,row,col,intial,color,n,m,vis);
        return grid;
    }
};