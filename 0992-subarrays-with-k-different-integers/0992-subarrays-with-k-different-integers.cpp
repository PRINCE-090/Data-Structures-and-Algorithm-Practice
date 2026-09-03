class Solution {
public:
     int atmost(vector<int>&nums,int k){
        int n = nums.size();
        if(k < 0) return 0;
        int total = 0,left = 0;
        unordered_map<int,int>mp;
        for(int right = 0;right < n;right++){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if((mp[nums[left]]) == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            total += (right - left +1);
        }
        return total;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);

    }
};