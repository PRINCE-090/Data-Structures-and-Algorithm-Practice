class Solution {
public:
    bool mintime(vector<int>&arr,int bookie,int adjacent,long long mid){
        long long limit = 0;
        int booquet = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > mid) limit = 0;
            else{
                limit++;
                if(limit == adjacent){
                    booquet++; 
                    limit = 0;
                }
            }
        }
        if(booquet < bookie) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long left = *min_element(bloomDay.begin(),bloomDay.end());
        long long right = *max_element(bloomDay.begin(),bloomDay.end());
        int days = 0;
        if(n < (long long)m*k) return -1;
        while(left <= right){
            long long mid = left+(right - left)/2;
            if(mintime(bloomDay,m,k,mid)){
                days = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return days;
    }
};