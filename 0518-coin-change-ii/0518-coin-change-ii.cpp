class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long>prev(amount+1,0),curr(amount+1,0);
        for(int i = 0;i<=amount;i++){
            if(i%coins[0] == 0) prev[i] = 1;
            else prev[i] = 0;
        }
        for(int idx = 1;idx<n;idx++){
            for(int target = 0;target<=amount;target++){
               unsigned long long notTake = prev[target];
               unsigned long long take = 0;
                if(coins[idx] <= target){
                 take = curr[target-coins[idx]];
                }
                curr[target] = notTake+take;
            } 
             prev = curr; 
        }
        return (int) prev[amount];
    }
};