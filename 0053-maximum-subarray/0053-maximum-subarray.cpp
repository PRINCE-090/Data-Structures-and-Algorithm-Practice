class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n = nums.size();
     int maxsum = INT_MIN, currsum = 0;
     for(int num : nums){
      currsum = max(currsum+num,num);
      maxsum = max(maxsum,currsum);
      if(currsum < 0) currsum = 0;
     }
    
     return maxsum;
    }
};