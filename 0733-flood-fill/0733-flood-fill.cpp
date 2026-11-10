// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,int n,int m,int color,int intialcolor){
        image[row][col] = color;
        const static int x[4] = {-1,1,0,0};
        const static int y[4] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int nrow = row + x[i];
            int ncol = col + y[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == intialcolor){
                dfs(image,nrow,ncol,n,m,color,intialcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int intialcolor = image[sr][sc];
       if(image[sr][sc] == color) return image;
        dfs(image,sr,sc,n,m,color,intialcolor);

        return image;
    }
};

// bfs
class Solution {
public: 
    void bfs(vector<vector<int>>&arr,int row,int col,int n,int m ,int color){
        int delRow[] = {0,0,1,-1};
        int delcol[] = {1,-1,0,0};
        int intial = arr[row][col];
      queue<pair<int,int>>q;
      q.push({row,col});
      arr[row][col] = color;
      while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
         for(int i = 0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col +delcol[i];
            if(nrow >=0 && ncol >=0 && nrow <n && ncol <m && arr[nrow][ncol] == intial
           ){
              arr[nrow][ncol] = color; 
                q.push({nrow,ncol});
            }
         }
      }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
       if(image[sr][sc] == color) return image;
        bfs(image,sr,sc,n,m,color);

        return image;
    }
};
