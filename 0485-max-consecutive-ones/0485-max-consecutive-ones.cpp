class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int maxone = 0, ones = 0;
     for(int i = 0;i<nums.size();i++){
      if(nums[i] == 1){
        ones++;
        maxone = max(maxone,ones);
      }
      else ones = 0;
     }
     return maxone;
    }
};