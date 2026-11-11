class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1,c2 = cost2,cb = costBoth,n1 = need1,n2 = need2;
        long long combinecost = c1 * n1 + c2 * n2;
        long long common = min(n1,n2);
        long long remaining_cost = (need1 > need2) ? (n1 - n2) * c1 : (n2 - n1) * c2;
        long long mixedbuy = common * cb + remaining_cost;
        long long bothcost = max(n1,n2) * cb;

        return min({combinecost,bothcost,mixedbuy});
    }
};