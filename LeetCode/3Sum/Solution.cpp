1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        vector<vector<int>>res;
7        for(int i = 0;i<n;i++){
8          if(i > 0 && nums[i] == nums[i-1]) continue;
9          long long sum = -1*nums[i];
10          int left = i+1, right = n-1;
11          while(left < right){
12            long long s = nums[left]+nums[right];
13            if(s == sum){
14              res.push_back({nums[i],nums[left],nums[right]});
15              left++;
16              right--;
17            while(left < right && nums[left] == nums[left-1]) left++;
18            while(left < right && nums[right] == nums[right+1]) right--;
19            }
20            else if(s > sum) right--;
21            else left++;
22          }
23        }
24      return res;
25    }
26};