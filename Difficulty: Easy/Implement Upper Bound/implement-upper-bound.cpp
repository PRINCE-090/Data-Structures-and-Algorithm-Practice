class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0 , right = n-1;
        int pos = n;
        while(left <= right){
            long long mid = left +(right - left)/2;
            if(arr[mid] > target){
                pos = mid;
                right = mid-1;
            }
            else {
                left = mid+1;;
            }
        }
        return pos;
        
    }
};
