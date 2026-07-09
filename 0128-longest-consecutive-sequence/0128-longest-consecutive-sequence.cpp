class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size() ==0) return 0;
      sort(nums.begin(),nums.end());
      int n = nums.size();
      int maxseq = 1, seq = 1;
      for(int i = 1;i<n;i++){
          if(nums[i] - nums[i-1] == 0) continue;
         else if(nums[i] - nums[i-1] ==1){
            seq++;
            maxseq = max(seq,maxseq);
          }
          else{
            seq = 1;
          }
      }
      return maxseq;
      }
};