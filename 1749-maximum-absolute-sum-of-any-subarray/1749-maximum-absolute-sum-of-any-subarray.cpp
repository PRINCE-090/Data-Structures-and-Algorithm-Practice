class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currsum = 0, currsum2 = 0;
        int maxsum = INT_MIN, minsum = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            currsum += nums[i];
            currsum2 += nums[i];
            maxsum = max(currsum,maxsum);
            minsum = min(minsum,currsum2);

            if(currsum < 0) currsum = 0;
            if(currsum2 > 0) currsum2 = 0;
        }
        return max(abs(minsum),abs(maxsum));
    }
};