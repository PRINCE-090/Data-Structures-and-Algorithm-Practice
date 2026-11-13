class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int n = mat.size();
      int m = mat[0].size();
      vector<vector<int>>dist(n,vector<int>(m,1e9));
      vector<vector<int>>vis(n,vector<int>(m,0));
      queue<pair<pair<int,int>,int>>q;
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                vis[i][j] = 0;
            }
        }
     }
     static const int x[4] = {-1,1,0,0};
     static const int y[4] = {0,0,1,-1};
      while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = min(steps,dist[row][col]);
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];

            if(nrow >= 0 && ncol < m && nrow < n && ncol >= 0 && !vis[nrow][ncol]){
                q.push({{nrow,ncol},steps+1});
                vis[nrow][ncol] = 1;
            }
        }
      }
      return dist;
    }
};