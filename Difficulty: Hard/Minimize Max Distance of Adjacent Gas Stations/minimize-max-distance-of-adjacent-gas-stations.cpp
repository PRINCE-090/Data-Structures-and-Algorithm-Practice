class Solution {
  public:
    int noOfStationRequired(long double dist,vector<int>&arr){
        int cnt = 0;
        for(int i = 1;i<arr.size();i++){
            int inBetween = ((arr[i] - arr[i-1])/dist);
            if((arr[i] - arr[i-1])/dist == inBetween *dist){
                inBetween--;
            }
            cnt+= inBetween;
        }
        return cnt;
    }
    double minMaxDist(vector<int> &stations, int k) {
       long double low = 0;
       long double high = 0;
       for(int i = 0;i<stations.size()-1;i++){
           high = max(high,((long double)stations[i+1] - stations[i]));
       }
       long double diff = 1e-6;
       while(high - low > diff){
           long double mid = (low + high)/(2.0);
           int cnt = noOfStationRequired(mid,stations);
           if(cnt > k){
               low = mid;
           }
           else{
               high = mid;
           }
       }
        return high;
    }
};