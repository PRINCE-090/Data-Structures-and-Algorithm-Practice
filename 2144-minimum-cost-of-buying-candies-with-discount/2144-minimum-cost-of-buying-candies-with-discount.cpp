class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        sort(cost.begin(),cost.end(),greater<>());
        int totalcost = 0;
       for(int i = 0;i<n;i++){
        if((i+1) % 3 != 0){
            totalcost += cost[i];
        }
       }
        return totalcost;
    }
};