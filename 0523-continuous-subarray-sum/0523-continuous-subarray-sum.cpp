class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp{{0,-1}};
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum = (nums[i] + sum) % k;
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            else if(i - mp[sum] > 1) return true;
        }
        return false;
    }
};