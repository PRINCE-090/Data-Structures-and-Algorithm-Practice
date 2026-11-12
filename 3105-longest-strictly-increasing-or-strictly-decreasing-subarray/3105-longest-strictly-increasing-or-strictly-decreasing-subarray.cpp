class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incnt = 1 ,decnt = 1, maxcnt = 1;
        for(int i = 0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                incnt++;
                maxcnt = max(maxcnt,incnt);
                decnt = 1;
            }
            else if(nums[i] > nums[i+1]) {
                decnt++;
                maxcnt = max(maxcnt,decnt);
                incnt = 1;
            }
            else {
                incnt = 1;
                decnt = 1;
            }
        }
        return maxcnt;
    }
};