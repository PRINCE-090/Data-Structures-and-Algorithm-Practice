class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int row,int col){
        if(row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size() || grid2[row][col] == 0)
        return true;
        grid2[row][col] = 0;
        bool check = (grid1[row][col] == 1);
          
        bool up = dfs(grid1,grid2,row-1,col); 
        bool down = dfs(grid1,grid2,row+1,col); 
        bool left = dfs(grid1,grid2,row,col-1); 
        bool right = dfs(grid1,grid2,row,col + 1); 

        return check && up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int subIsland = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[i][j] == 1){
                   if(dfs(grid1,grid2,i,j)) subIsland++;
                }
            }
        }
        return subIsland;
    }
};