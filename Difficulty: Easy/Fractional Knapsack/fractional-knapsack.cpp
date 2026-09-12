class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
         vector<pair<double,pair<int,int>>>arr;
         for(int i = 0;i<n;i++){
             double ratio = (double) val[i] / wt[i];
             arr.push_back({ratio,{val[i],wt[i]}});
         }
        sort(arr.rbegin(),arr.rend());
        double totalprofit = 0;
        for(auto num : arr){
            double ratio = num.first;
            int val = num.second.first;
            int wt = num.second.second;
            
            if(wt <= capacity){
                totalprofit += val;
                capacity -= wt;
            }
            else {
                totalprofit += capacity * ratio;
                break;
            }
        }
        return totalprofit;
        
    }
};
