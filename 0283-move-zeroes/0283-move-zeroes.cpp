class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      if(nums.size() == 1 || nums.size() == 0) return;
     int left = 0, i;
     for(i = 0;i<nums.size();i++){
      if(nums[i] == 0){
        left = i;
        break;
      }
     }
     for(int right = i+1;right<nums.size();right++){
        if(nums[right] != 0){
          swap(nums[right] , nums[left]);
          left++;
        }
     }

    }
};