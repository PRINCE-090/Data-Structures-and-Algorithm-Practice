class Solution {
  public:
   int find(int mid,int n,int m){
       long long val = 1;
       for(int i = 1;i<=n;i++){
           val = val*mid;
           if(val > m) return 2;
       }
       if(val == m) return 1;
       return 0;
   }
    int nthRoot(int n, int m) {
        int left = 0,right = m;
        while(left <= right){
            long long mid = left+(right-left)/2;
            int midm = find(mid,n,m);
            if(midm == 1){
                return mid;
            }
            else if(midm == 2){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
            
        }
        return -1;
    }
};