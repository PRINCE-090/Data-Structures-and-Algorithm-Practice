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


// using bit manupulation 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>>ans;
        for(int num = 0;num<subsets;num++){
            vector<int>subset;
            for(int i = 0;i<n;i++){
                if(num & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
