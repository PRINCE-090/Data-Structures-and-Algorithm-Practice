class Solution {
public:
  // deep rivision needes
    int findKthPositive(vector<int>& arr, int k) {
      int left = 0,right = arr.size()-1;
      while(left <= right){
        long long mid = left +(right - left)/2;
        long long miss = arr[mid] - (mid+1);
        if(miss >= k){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
      }
      return left+k;
    }
};