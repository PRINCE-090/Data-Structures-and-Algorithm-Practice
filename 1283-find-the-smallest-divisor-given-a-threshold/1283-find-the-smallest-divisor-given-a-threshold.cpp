class Solution {
public:
    bool checkdivison(vector<int>&nums,int limit,long long mid){
        if(mid == 0) return false;
        int totaldivison = 0;
        for(int i = 0;i<nums.size();i++){
           totaldivison += (nums[i]+mid-1)/mid;
           if(totaldivison > limit) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long left = 1,right = *max_element(nums.begin(),nums.end());
        long long val = 0;
        while(left <= right){
            long long mid = left+(right-left)/2;
            if(checkdivison(nums,threshold,mid)){
                val = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return val;
    }
};