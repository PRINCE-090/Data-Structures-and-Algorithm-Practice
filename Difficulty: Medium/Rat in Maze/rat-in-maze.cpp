class Solution {
  public:
    void findways(int row,int col,int n,string move,vector<vector<int>>&maze,
    vector<string>&ans,vector<vector<int>>&vis)
    {
        if(row == n-1 && col == n-1){
            ans.push_back(move);
            return;
        }
        // DOWN
        if(row + 1 < n && maze[row+1][col] == 1 && !vis[row+1][col]){
            vis[row][col] = 1;
            findways(row + 1,col,n,move + 'D' , maze,ans,vis);
            vis[row][col] = 0;
        }
        // LEFT 
        if(col - 1 >= 0 && maze[row][col-1] == 1 && !vis[row][col-1]){
            vis[row][col] = 1;
            findways(row,col-1,n,move + 'L',maze,ans,vis);
            vis[row][col] = 0;
        }
        // RIGHT
        if(col + 1 < n && maze[row][col+1] == 1 && !vis[row][col+1]){
            vis[row][col] = 1;
            findways(row,col+1,n,move + 'R',maze,ans,vis);
            vis[row][col] = 0;
        }
        // UP
        if(row - 1 >= 0 && maze[row-1][col] == 1 && !vis[row-1][col]){
            vis[row][col] = 1;
            findways(row-1,col,n,move + 'U',maze,ans,vis);
            vis[row][col] = 0;
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(maze[0][0] != 1) return ans;
         findways(0,0,n,"",maze,ans,vis);
        return ans;
    }
};