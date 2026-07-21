class Solution {
public:
  bool leastcapacity(long long mid , vector<int>&arr,int days){
     long long day = 1,total = 0, val = mid;
     for(int i = 0;i<arr.size();i++){
        if(arr[i] > mid) return false;
        if((total + arr[i]) > mid){
            day++;
            total = arr[i];
        }
        else{
            total += arr[i];
        }
        if(day > days) return false;
     }
    return true;
  }
    int shipWithinDays(vector<int>& weights, int days) {
        long long right = std::reduce(weights.begin(),weights.end(),0LL);
        long long left = 1;
        int val = right;
        while(left <= right){
            long long mid = left +(right - left)/2;
            if(leastcapacity(mid,weights,days)){
                val = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return val;
    }
};