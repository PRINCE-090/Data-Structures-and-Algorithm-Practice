class Solution {
public:
    int checksum(long long mid,vector<int>&nums){
        int min = 1;
        long long maxsum = 0;
        for(int i = 0;i<nums.size();i++){
            if(maxsum + nums[i] <= mid){
                maxsum += nums[i];
            }
            else{
                min++;
                maxsum = nums[i];
             }
        }
        return min;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        long long left = *max_element(nums.begin(),nums.end());
        long long right = accumulate(nums.begin(),nums.end(),0);
        while(left <= right){
            long long mid = left+(right-left)/2;
            int maxsum = checksum(mid,nums);
            if(maxsum > k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};