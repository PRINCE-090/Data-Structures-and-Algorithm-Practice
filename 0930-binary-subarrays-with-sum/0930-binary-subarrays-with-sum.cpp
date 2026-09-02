class Solution {
public:
      int atmost(vector<int>&nums,int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int total = 0,curr = 0;
        int left = 0;
        for(int right = 0;right <n;right++){
            curr+= nums[right];
            while(left <=right &&curr > goal){
                curr -= nums[left];
                left++;
            }
           total += right-left+1;
        }
       
        return total;
      }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atmost(nums,goal) - atmost(nums,goal-1);
    }
};