1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        vector<int>ans;
5        int el1 = 0,el2 = 0,cnt1 =0,cnt2 = 0;
6        for(int i = 0;i<nums.size();i++){
7          if(cnt1 == 0 && nums[i] != el2){
8            el1 = nums[i];
9            cnt1++;
10          }
11          else if(nums[i] == el1) cnt1++;
12          else if(cnt2 == 0 && nums[i] != el1){
13            el2 = nums[i];
14            cnt2++;
15          }
16          else if(nums[i] == el2) cnt2++;
17          else {
18            cnt1--;
19            cnt2--;
20          }
21        }
22        cnt1 = 0,cnt2 = 0;
23        for(int i = 0;i < nums.size();i++){
24          if(nums[i] == el1) cnt1++;
25          else if(nums[i] == el2) cnt2++;
26        }
27        int  n = (nums.size()/3)+1;
28        if(cnt1 >= n){
29          ans.push_back(el1);
30        }
31        if(cnt2 >= n){
32          ans.push_back(el2);
33        }
34        sort(ans.begin(),ans.end());
35        return ans;
36    }
37};