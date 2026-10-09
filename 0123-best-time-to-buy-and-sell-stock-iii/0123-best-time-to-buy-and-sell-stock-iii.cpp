class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long long buy1 = INT_MAX, buy2 = INT_MAX,profit = 0, profit2 = 0;
        for(int i  = 0;i<n;i++){
            buy1 = min(buy1,(long long)prices[i]);
            profit = max(profit,prices[i] - buy1);
            buy2 = min(buy2,(long long)prices[i] - profit);
            profit2 = max(profit2,prices[i] - buy2);
        }
        return profit2;
    }
};