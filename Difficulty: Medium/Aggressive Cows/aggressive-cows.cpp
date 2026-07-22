class Solution {
  public:
    bool validCows(vector<int>&arr,int limit,long long mid){
        int n = arr.size();
        long long curr = arr[0], countCow = 1;
        for(int i = 1;i<n;i++){
            if(arr[i] - curr >= mid){
                countCow++;
                curr = arr[i];
            }
            if(countCow >= limit) return true;
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        long long left = 1, right = arr[n-1] - arr[0];
        int minDistance = -1;
        while(left <= right){
            long long mid = left+(right - left)/2;
            if(validCows(arr,k,mid)){
                minDistance = mid;
                 left = mid+1;
               
            }
            else{
               right = mid-1;  
            }
        }
        return minDistance;
        
    }
};