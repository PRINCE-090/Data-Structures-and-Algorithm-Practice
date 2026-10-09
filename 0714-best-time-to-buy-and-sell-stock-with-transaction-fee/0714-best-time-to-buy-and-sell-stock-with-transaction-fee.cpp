class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int currbuy= 0,currnotbuy =0,aheadbuy = 0,aheadnotbuy = 0;
        for(int ind = n-1;ind>=0;ind--){
            currbuy = max(-prices[ind]+aheadnotbuy,aheadbuy);
            currnotbuy = max(prices[ind] - fee + aheadbuy,aheadnotbuy);

            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};