1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        vector<int>ls;
5        int cnt1 = 0,cnt2 = 0;
6        int el1 = INT_MIN, el2 = INT_MIN;
7        for(int i =0;i<nums.size();i++){
8            if(cnt1 == 0 && nums[i] != el2){
9                cnt1++;
10                el1 = nums[i];
11            }
12            else if(cnt2 == 0 && nums[i]!= el1){
13                cnt2++;
14                el2 = nums[i];
15            }
16            else if(nums[i] == el1) cnt1++;
17            else if(nums[i] == el2) cnt2++;
18            else cnt1--, cnt2--;
19        }
20        int co1=0,co2=0;
21        for(int i =0;i<nums.size();i++){
22            if(el1 == nums[i]) co1++;
23            if(el2 == nums[i]) co2++;
24        }
25        int n = (int)(nums.size()/3)+1 ;
26       if(co1 >= n) ls.push_back(el1);
27       if(co2 >= n) ls.push_back(el2);
28
29       sort(ls.begin(),ls.end());
30
31       return ls;
32    }
33};