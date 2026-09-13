class Solution {
public:
    int jump(vector<int>& nums) {
        int n  = nums.size();
        int jumps = 0, left = 0, right = 0;
        while(right < n-1){
          int farthest = 0;
          for(int idx = left;idx<=right;idx++){
            farthest = max(idx + nums[idx],farthest);
          }
          left = right+1;
          right = farthest;
          jumps++;
        }
        return jumps;
    }
};