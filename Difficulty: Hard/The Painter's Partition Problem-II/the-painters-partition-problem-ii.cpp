class Solution {
  public:
  bool validPaint(vector<int>&arr,int k,long long mid,int n){
      int painter = 1;
      long long total = 0;
      for(int i = 0;i<n;i++){
          if(arr[i] > mid) return false;
          if(arr[i] + total <= mid){
              total += arr[i];
          }
          else{
              painter++;
              total = arr[i];
          }
          if(painter > k) return false;
      }
      return true;
  }
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        long long left = *max_element(arr.begin(),arr.end());
        long long right = std::reduce(arr.begin(),arr.end(),0LL);
        long long  minAmount = 0;
        while(left <= right){
            long long mid  = left + (right - left)/2;
            if(validPaint(arr,k,mid,n)){
                minAmount = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return minAmount;
        
    }
};