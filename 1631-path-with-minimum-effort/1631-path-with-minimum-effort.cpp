class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        while(!pq.empty()){
            int effords = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row == n-1 && col == m-1) return effords;

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int neweffords = max(abs(heights[row][col] - heights[nrow][ncol]),effords);
                    if(dist[nrow][ncol] > neweffords){
                        dist[nrow][ncol] = neweffords;
                        pq.push({neweffords,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};