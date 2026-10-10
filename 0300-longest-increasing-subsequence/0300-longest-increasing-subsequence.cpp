class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] > temp.back()){
                len++;
                temp.push_back(nums[i]);
            }
            else{
             *lower_bound(temp.begin(),temp.end(),nums[i]) = nums[i];
                
            }
        }
        return len;
    }
};