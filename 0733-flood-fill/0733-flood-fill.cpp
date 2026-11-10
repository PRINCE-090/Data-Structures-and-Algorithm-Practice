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