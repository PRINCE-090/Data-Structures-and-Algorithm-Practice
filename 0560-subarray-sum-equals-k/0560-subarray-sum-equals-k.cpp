class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, x=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i = 0;i<n;i++){
          x += nums[i];
          int prefixsum = x-k;
          if(mp.find(prefixsum) != mp.end()){
            cnt += mp[prefixsum];
          }
          mp[x]++;
        }
      
        return cnt;
    }
};