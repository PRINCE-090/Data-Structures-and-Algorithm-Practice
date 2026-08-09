class Solution {
  public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&vec,
    int row,int col,int row0,int col0,int n,int m){
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        
        for(int k = 0;k<4;k++){
            int nrow = row+delRow[k];
            int ncol = col+delCol[k];
            
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !vis[nrow][ncol] 
            && grid[nrow][ncol] == 'L' ){
                dfs(grid,vis,vec,nrow,ncol,row0,col0,n,m);
            }
        }
    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    vector<pair<int,int>>vec;
                    dfs(grid,vis,vec,i,j,i,j,n,m);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
