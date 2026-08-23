class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        queue<pair<int,pair<int,int>>>q;
        if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0){
            return -1;
        }
        if(src[0] == dest[0] && src[1] == dest[1]){
            return 0;
        }
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src[0]][src[1]] = 0;
        q.push({0,{src[0],src[1]}});
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == dest[0] && c == dest[1]){
                        return dis;
                    }
            for(int i = 0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1
                 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    q.push({1 + dis,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};
