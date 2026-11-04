class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size());
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            ans[i] = curr + nums[i];
            curr += nums[i];
        }
        return ans;
    }
};