class Solution {
public:
   void merge(int low,int mid,int high,vector<int>&arr){
    vector<int>temp;
    int left = low;
    int right  = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
           temp.push_back(arr[left]);
           left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
   }
    int countpairs(int low,int mid,int high,vector<int>&nums){
     int cnt = 0;
     int right = mid+1;
     for(int i = low;i<=mid;i++){
        while(right <= high && (long long)nums[i] > 2LL * nums[right]) right++;
        cnt += (right-(mid+1));
     }
     return cnt;
    }
    int mergesort(int low,int high,vector<int>&nums){
       int cnt = 0;
       long long mid = (low+high)/2;
       if(low >= high) return cnt;
      cnt+= mergesort(low,mid,nums);
      cnt+= mergesort(mid+1,high,nums);
      cnt+= countpairs(low,mid,high,nums);
       merge(low,mid,high,nums);
       return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);    
    }
};