1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        sort(nums.begin(),nums.end());
5        int n = nums.size();
6        vector<vector<int>>res;
7        for(int i = 0;i<n;i++){
8             if(i>0 && nums[i] == nums[i-1]) continue;
9            for(int j = i+1;j<n;j++){
10                if(j > (i+1) && nums[j] == nums[j-1]) continue;
11                int left = j+1, right = n-1;
12                while(left < right)
13                {
14                long long pointerSum = nums[i]+nums[j];
15                long long sum = target - pointerSum;
16                if(sum == nums[left]+ nums[right]){
17                    res.push_back({nums[i],nums[j],nums[left],nums[right]});
18                    left++, right--;
19                    while(left<right && nums[left] == nums[left-1]) left++;
20                    while(left < right && nums[right] == nums[right+1]) right--;
21                }
22                else if(sum >(nums[left] + nums[right])) left++;
23                else right--;
24                }
25            }
26        }
27        return res;
28    }
29};