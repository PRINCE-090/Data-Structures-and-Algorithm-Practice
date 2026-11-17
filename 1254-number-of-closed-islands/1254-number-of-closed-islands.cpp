class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i < 0 || i>= n || j < 0 || j >= m) return false;

        if(grid[i][j] == 1 || grid[i][j] == -1) return true;

        grid[i][j] = -1;

        bool up = dfs(i-1,j,n,m,grid);
        bool down = dfs(i+1,j,n,m,grid);
        bool left = dfs(i,j-1,n,m,grid);
        bool right = dfs(i,j+1,n,m,grid);

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                  if(dfs(i,j,n,m,grid)) cnt++;
                }
            }
        }
        return cnt;
    }
};