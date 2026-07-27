class Solution {
public:
   void backtrack(int i,int n , vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    if(i == n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    backtrack(i+1,n,nums,temp,ans);
    temp.pop_back();
    backtrack(i+1,n,nums,temp,ans);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>>ans;
          vector<int>temp;
          backtrack(0,nums.size(),nums,temp,ans);
          return ans;
    }
};