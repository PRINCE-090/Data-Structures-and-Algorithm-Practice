class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int el1 = 0,el2 = 0,cnt1 =0,cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
          if(cnt1 == 0 && nums[i] != el2){
            el1 = nums[i];
            cnt1++;
          }
          else if(nums[i] == el1) cnt1++;
          else if(cnt2 == 0 && nums[i] != el1){
            el2 = nums[i];
            cnt2++;
          }
          else if(nums[i] == el2) cnt2++;
          else {
            cnt1--;
            cnt2--;
          }
        }
        cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < nums.size();i++){
          if(nums[i] == el1) cnt1++;
          else if(nums[i] == el2) cnt2++;
        }
        int  n = (nums.size()/3)+1;
        if(cnt1 >= n){
          ans.push_back(el1);
        }
        if(cnt2 >= n){
          ans.push_back(el2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};