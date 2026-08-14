class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,size = 1e9;
        long long sum = 0;
       for(int right = 0;right < nums.size();right++){
        sum+=nums[right];
        while(sum >= target){
            sum -= nums[left];
            size = min(size,right-left+1);
            left++;
        }
       }
       if(size == 1e9) return 0;
       return size;
    }
};