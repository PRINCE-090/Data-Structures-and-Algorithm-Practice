class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isWater[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        static const int x[4] = {-1,1,0,0};
        static const int y[4] = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int i = 0;i<4;i++){
                int nrow = row + x[i];
                int ncol = col + y[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && isWater[nrow][ncol] == 0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol] = 1;
                }
            } 
        }
        return dist;
    }
};