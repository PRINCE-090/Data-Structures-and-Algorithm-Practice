class Solution {
public:
  void solve(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int shiftElem = grid[n-1][m-1];
    for(int i = 0;i<n;i++){
     for(int j = 0;j<m;j++){
      int x = grid[i][j];
      grid[i][j] = shiftElem;
      shiftElem = x;
      }
    }
  }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i = 0;i<k;i++){
            solve(grid);
        }
        return grid;
    }
};