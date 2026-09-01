class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int total = 0,curr = 0;
        for(int i = 0;i<n;i++){
            curr = 0;
            for(int j = i;j<n;j++){
              curr += nums[j];
              if(curr == goal) total++;
              if(curr > goal) break;
            }
        }
        return total;
    }
};