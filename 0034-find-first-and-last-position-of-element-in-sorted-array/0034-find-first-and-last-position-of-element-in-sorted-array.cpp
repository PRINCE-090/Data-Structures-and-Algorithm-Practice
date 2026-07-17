class Solution {
public:
  int lastPosition(vector<int>&nums,int target,int n){
    int left = 0, right = n-1,last = -1;
    while(left <= right) {
        long long mid = left +(right - left)/2;
        if(nums[mid] == target)
        {
           last = mid;
           left = mid+1;
        }
        else if(nums[mid] < target){
          left = mid+1;
        }
        else{
          right = mid-1;
        }
       }
       return last;
  }
  int firstPosition(vector<int>&nums,int target,int n){
    int left = 0,right = n-1, first = -1;
    while(left <= right) {
        long long mid = left +(right - left)/2;
        if(nums[mid] == target)
        {
           first = mid;
           right = mid-1;
        }
        else if(nums[mid] < target){
          left = mid+1;
        }
        else{
          right = mid-1;
        }
       }
       return first;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n = nums.size();
       int first = firstPosition(nums,target,n);
       if(first == -1) return {-1,-1};
       int last = lastPosition(nums,target,n);
       
       return {first,last};
    }
};