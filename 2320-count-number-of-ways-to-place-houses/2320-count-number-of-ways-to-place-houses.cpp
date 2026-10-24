class Solution {
public:
    int mod = 1e9 + 7;
    int countHousePlacements(int n) {
        if(n == 1)return 4;
        if(n == 2) return 9;
        long long prev2 = 2;
        long long prev = 3;
        for(int i = 3;i<=n;i++){
            int placehouse = prev2;
            int notplace = prev;
            long long curr = (prev2 + prev) % mod;
           prev2 = prev;
            prev = curr;
        }
         
        return (prev*prev)%mod;
    }
};