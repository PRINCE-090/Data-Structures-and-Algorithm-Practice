class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int minOperations = 0;
        for(auto it : mp){
            if(it.second == 1) return -1;
            else{
                if(it.second % 3 == 0) minOperations += it.second/3;
                else{
                    minOperations += it.second/3 + 1;
                }
            }

        }
        return minOperations;
    }
};