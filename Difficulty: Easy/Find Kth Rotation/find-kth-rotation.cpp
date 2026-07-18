class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
       int left = 0, right = n-1;
       int rotated = 0;
       while(left <= right){
           long long mid = left + (right-left)/2;
           if(arr[mid] > arr[n-1]){
               left = mid+1;
           }
           else{
               rotated = mid;
               right = mid-1;
           }
       }
       return rotated;
    }
};
