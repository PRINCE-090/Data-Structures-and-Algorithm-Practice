class Solution {
public:
    int base = 100007;
    int mod = 1e9 + 7;

    bool possible(vector<int>&nums,int k){
        int n = nums.size();
        unordered_map<long long,int>mp;

        long hash = 0;
        long power = 1;
        for(int i = 0;i<k;i++){
            hash = (hash * base + nums[i])%mod;

            if(i < k-1){
                power = (power * base)%mod;
            }
        }
        mp[hash]++;
        for(int i = k;i<n;i++){
            hash = (hash - nums[i-k] * power %mod + mod) %mod;
            hash = (hash * base + nums[i]) %mod;

            mp[hash]++;
        }
        for(auto it : mp){
            if(it.second == 1) return true;
        }
        return false;
    }


    int smallestUniqueSubarray(vector<int>& nums) {
        int left = 1, right  = nums.size();
        int ans = nums.size();
        while(left <= right){
            int mid = (left + right)/2;
            if(possible(nums,mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};