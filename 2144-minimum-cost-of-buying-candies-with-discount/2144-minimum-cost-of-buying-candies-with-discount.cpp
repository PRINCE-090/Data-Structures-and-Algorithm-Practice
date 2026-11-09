class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        sort(cost.begin(),cost.end(),greater<>());
        int i = 0, j = 1;
        int totalcost = 0;
        while(i < n && j < n){
            totalcost += cost[i] + cost[j];
            i+=3;
            j +=3;
        }
        if(i < n) totalcost+= cost[i];
        if(j < n) totalcost+= cost[j];
        return totalcost;
    }
};