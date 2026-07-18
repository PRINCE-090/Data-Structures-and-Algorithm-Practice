class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = n-1,val = INT_MAX;
        while(left <= right){
            long long mid = left +(right - left)/2;
            if(nums[left] <= nums[mid]){
                val = min(val,nums[left]);
                left = mid+1;
            }
            else{
                val = min(val,nums[mid]);
                right = mid-1;
            }
        }
        return val;
    }
};