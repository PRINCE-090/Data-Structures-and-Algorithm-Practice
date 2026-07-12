1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4    int n = nums.size();
5    if (n == 0) return {};
6    
7    sort(nums.begin(), nums.end());
8    vector<int> ans;
9    int target = n / 3;
10    
11    for (int i = 0; i < n; ) {
12        int cnt = 0;
13        int currentNum = nums[i];
14        while (i < n && nums[i] == currentNum) {
15            cnt++;
16            i++;
17        }
18        
19        if (cnt > target) {
20            ans.push_back(currentNum);
21        }
22    }
23    return ans;
24  } 
25};