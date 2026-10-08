class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadbuy,aheadnotbuy,currbuy,currnotbuy;
        aheadbuy = 0, aheadnotbuy = 0;
        for(int ind = n-1;ind>=0;ind--){
            currnotbuy = max(prices[ind] + aheadbuy , 0 + aheadnotbuy);

            currbuy = max(-prices[ind] + aheadnotbuy , 0 + aheadbuy);

            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
       return aheadbuy;
    }
};