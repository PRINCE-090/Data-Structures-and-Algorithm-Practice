class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0], worst = nums[0],sum = nums[0], maxans = nums[0], minans = nums[0];
        for(int i = 1;i<n;i++){
            int a = nums[i];
            int b = nums[i] + best;
            int c = nums[i] + worst;
            best = max(a,b);
            worst = min(a,c);
            maxans = max(best,maxans);
            minans = min(worst,minans);
            sum += nums[i];
        }
        if(maxans < 0) return maxans;
        int res = max(maxans , sum - minans);
        return res;
    }
};