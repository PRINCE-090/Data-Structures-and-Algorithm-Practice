class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0], worst = nums[0],sum = nums[0], maxans = nums[0], minans = nums[0];
        for(int i = 1;i<n;i++){
            int a = nums[i];
            int b = nums[i] + best;
            int c = nums[i] + worst;
            best = max(a,b);
            worst = min(a,c);
            maxans = max(best,maxans);
            minans = min(worst,minans);
            sum += nums[i];
        }
        if(maxans < 0) return maxans;
        int res = max(maxans , sum - minans);
        return res;
    }
};


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        int currsum = 0, maxsum = INT_MIN;
        int currsum2 = 0,minsum = INT_MAX ,totalsum = 0;
        for(int i = 0;i<n;i++){
            currsum+= arr[i];
            currsum2+= arr[i];
            totalsum+= arr[i];
            maxsum = max(maxsum , currsum);
            minsum = min(minsum , currsum2);
            if(currsum <0) currsum = 0;
            if(currsum2 >0) currsum2 = 0;
        }
       if(maxsum > 0) return max(maxsum , totalsum-minsum);
       return maxsum;
    } 
};
