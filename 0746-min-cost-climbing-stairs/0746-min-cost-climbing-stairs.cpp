class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       int prev2 = 0;
       int prev = cost[n-1];
        int minicost = INT_MAX;
        for(int ind = n-2;ind>=0;ind--){
            int onestep = cost[ind] + prev;
            int twostep = cost[ind] + prev2;
            int sum  =  min(onestep,twostep);
            prev2  = prev;
            prev = sum;
        }
        return min(prev2,prev);
    }
};