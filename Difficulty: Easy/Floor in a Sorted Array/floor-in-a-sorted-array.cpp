class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int flor = -1;
        int left = 0, right = n-1;
         while(left <= right){
             long long mid = left + (right-left)/2;
             if(arr[mid] <= x){
                 flor = mid;
                 left = mid+1;
             }
             else{
                 right = mid-1;
             }
         }    
         return flor;
    }
};
