class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int majorityElement = 0;
    int el = 0;
    for(int i = 0;i<nums.size();i++){
     if(majorityElement == 0){
        el = nums[i];
      }
      if(nums[i] == el){
        majorityElement++;
      }
      else{
        majorityElement--;
      }
    }
    majorityElement = 0;
    for(int i = 0;i<nums.size();i++){
      if(nums[i] == el){
        majorityElement++;
      }
    }
    if(majorityElement > (nums.size()/2)){
        return el;
    }
       return -1; 
    }
};