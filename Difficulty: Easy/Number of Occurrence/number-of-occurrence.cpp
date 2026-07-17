class Solution {
  public:
  int firstOccurence(vector<int>&arr,int x,int n){
      int left = 0,right = n-1;
      int first = -1;
      while(left <= right){
          long long mid = left + (right -left)/2;
          if(arr[mid] == x){
              first = mid;
              right = mid-1;
          }
          else if(arr[mid] > x){
              right = mid-1;
          }
          else{
              left = mid+1;
          }
      }
          return first;
  }
  int lastOccurence(vector<int>&arr,int x,int n){
      int left = 0,right = n-1;
      int last = -1;
      while(left <= right){
          long long mid = left + (right -left)/2;
          if(arr[mid] == x){
              last = mid;
              left = mid+1;
          }
          else if(arr[mid] > x){
              right = mid-1;
          }
          else{
              left= mid+1;
          }
      }
          return last;
  }
    int countFreq(vector<int>& arr, int target) {
        int freq = 0;
        int n = arr.size();
        int first = firstOccurence(arr,target,n);
        if(first == -1) return 0;
        int last = lastOccurence(arr,target,n);
        freq = last-first+1;
        return freq;
        
    }
};
