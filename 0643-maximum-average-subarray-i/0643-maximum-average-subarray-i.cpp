class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<k;i++){
            sum += nums[i];
        }
        double maxAverage = (double)sum /k;
        for(int i = k;i<n;i++){
            sum += nums[i];
            sum -= nums[i-k];
            maxAverage = max(maxAverage,(double)sum /k);
        }
        return maxAverage;
    }
};