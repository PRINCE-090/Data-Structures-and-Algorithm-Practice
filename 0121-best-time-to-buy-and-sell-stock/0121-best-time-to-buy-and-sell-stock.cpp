class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
       int maxprofit = 0,mini = prices[0];
       for(int i = 1;i<n;i++){
        int profit = prices[i] - mini;
        mini = min(mini,prices[i]);
        maxprofit = max(maxprofit,profit);
       }
      
       return maxprofit;
    }
};