class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
      if(nums.size() == 1) return 1;
      int left = 0,  freq = 1;
      long long sum = 0;
      sort(nums.begin(),nums.end());
      for(int right = 0;right < nums.size();right++){
        sum += nums[right];
        while((long long)nums[right]*(right-left+1)-sum >k){
          sum-=nums[left];
          left++;
        }
        freq = max(freq,right-left+1);
      }

      return freq;
    }
    
};