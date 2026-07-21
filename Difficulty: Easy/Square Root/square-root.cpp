class Solution {
  public:
    int floorSqrt(int n) {
        int sq = 0;
        for(int i = 1;i*i <= n;i++){
             sq = i;
            
        }
        return sq;
        
    }
};