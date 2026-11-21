class Solution {
public:
    bool dfs(int row,int col,int parentRow,int parentCol,vector<vector<char>>&grid,vector<vector<int>>&vis,char value,int n,int m){
    static const int x[4] = {-1,1,0,0};
    static const int y[4] = {0,0,-1,1};
        vis[row][col] = 1;
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == value){
                if(!vis[nrow][ncol]){
                if(dfs(nrow,ncol,row,col,grid,vis,value,n,m)) return true;
                }
               else if(nrow != parentRow && ncol != parentCol) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis,grid[i][j],n,m)) return true;
                }
            }
        }
        return false;
    }
};