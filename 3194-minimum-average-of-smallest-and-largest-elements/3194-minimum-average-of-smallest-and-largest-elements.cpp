class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<float>average;
        float min_average = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right){
          long long total = nums[left]+nums[right];
          float average = total/2.0;
          min_average = min(min_average,average);
          left++;
          right--;
        }
        return min_average;
    }
};