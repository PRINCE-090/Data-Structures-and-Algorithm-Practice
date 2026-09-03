class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
       int n = nums.size();
       int leftsum = 0, maxsum = 0, rightidx = n-1;
       int rightsum = 0;
       for(int left = 0;left < k;left++){
        leftsum += nums[left];
       }
       maxsum = leftsum;
       for(int i = k-1;i>=0;i--){
         leftsum -=nums[i];
          rightsum += nums[rightidx];
          rightidx--;

          maxsum = max(maxsum , (leftsum + rightsum));
       }
       return maxsum;
    }
};