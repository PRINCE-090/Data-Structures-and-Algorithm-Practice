class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1 , maxcnt = 1;
        for(int i = 0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                cnt++;
                maxcnt = max(maxcnt,cnt);
            }
            else {
                cnt = 1;
            }
        }
        cnt = 1;
        for(int i = 0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
              cnt++;
                maxcnt = max(maxcnt,cnt);
            }
            else {
                cnt = 1;
            }
        }
        return maxcnt;
    }
};