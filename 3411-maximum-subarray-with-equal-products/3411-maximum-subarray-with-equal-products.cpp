class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxlen = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++){
           long long prod = nums[i],GCD = nums[i],LCM = nums[i];
            for(int j = i+1;j<n;j++){
              if(prod > 1e14) break;
              prod *= nums[j];
              GCD = gcd(GCD,(long long)nums[j]);
              LCM = lcm(LCM,(long long)nums[j]);

              if(prod == GCD * LCM){
                maxlen = max(maxlen,j-i+1);
              }
            }
        }
        return maxlen;
    }
};