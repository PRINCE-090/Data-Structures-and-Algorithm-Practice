class Solution {
  public:
      int upperbound(vector<int>&mat,int x){
          int low = 0, high = mat.size()-1;
          int ans = mat.size();
          while(low <= high){
              int mid = low + (high-low)/2;
              if(mat[mid] > x){
                  ans = mid;
                  high = mid-1;
              }
              else{
                  low = mid+1;
              }
          }
          return ans;
      }
     int findsmaller(vector<vector<int>>&mat,int m,int n,int x){
         int cnt = 0;
         for(int i = 0;i<n;i++){
             cnt += upperbound(mat[i],x);
         }
         return cnt;
     }
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = mat[0][0], high = mat[0][m-1];
        for(int i = 0;i<n;i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][m-1]);
        }
        int req = (m*n)/2;
        while(low <= high){
            int mid = low+(high-low)/2;
            int countsmaller = findsmaller(mat,m,n,mid);
            if(countsmaller <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
