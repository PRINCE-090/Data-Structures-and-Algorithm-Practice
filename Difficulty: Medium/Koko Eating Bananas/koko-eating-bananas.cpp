class Solution {
  public:
  
    bool eatbanana(vector<int>&arr,long long mid,int k,int n){
        int hours = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] < mid) hours++;
            else{
                hours += arr[i]/mid;
                if(arr[i] % mid != 0 ) hours++;
                
            }
            if(hours > k) return false;
        }
        return true;
        
        
    }
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
       long long left = 1;
        long long right = *max_element(arr.begin(),arr.end());
        int minbanana = 0;
        while(left <= right){
            long long mid = left + (right - left)/2;
            if(eatbanana(arr,mid,k,n)){
                minbanana = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return minbanana;
        
    }
};