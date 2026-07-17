class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
    int n = arr.size();
    int ceils = -1, left = 0,right = n-1;
    while(left <= right){
        long long mid = left + (right-left)/2;
        if(arr[mid] >= x){
            ceils = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return ceils;
        
    }
};