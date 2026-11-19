class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int firstTwo  = nums[n-1] - nums[2];
        int firstLast = nums[n-2] - nums[1];
        int lastTwo = nums[n-3] - nums[0];
        int score = min({firstTwo,firstLast,lastTwo});
        return score;
    }
};