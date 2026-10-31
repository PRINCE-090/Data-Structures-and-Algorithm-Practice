class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>prev = grid[0];
        for(int i = 1;i<n;i++){
         int firstmin = INT_MAX,secondmin = INT_MAX;
         int firstminIndex = -1;

         for(int  j= 0;j<n;j++){
            if(prev[j] < firstmin){
                secondmin = firstmin;
                firstmin = prev[j];
                firstminIndex = j;
            } else if(prev[j] < secondmin){
                secondmin = prev[j];
            }
         }
         vector<int>curr(n);
         for(int k = 0;k<n;k++){
            if(k != firstminIndex){
                curr[k] =  grid[i][k]+firstmin;
            }
            else{
                curr[k] = grid[i][k] + secondmin;
            }
         }
         prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};