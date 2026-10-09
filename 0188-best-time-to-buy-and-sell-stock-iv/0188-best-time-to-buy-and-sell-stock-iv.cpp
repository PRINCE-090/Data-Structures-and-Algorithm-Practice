class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
       vector<int>after(2*k+1,0);
       vector<int>curr(2*k+1,0); 
        for(int ind = n-1;ind>=0;ind--){
            for(int cap = 2*k-1;cap>=0;cap--){
                long maxprofit = 0;
                if(cap % 2 == 0){
                   maxprofit = max(-prices[ind] + after[cap+1] ,after[cap]);
                }
                else{
                  maxprofit = max(prices[ind] + after[cap+1], after[cap]);
                }
               curr[cap] = maxprofit;
            }
            after = curr;
        }
        return after[0];
    }
};