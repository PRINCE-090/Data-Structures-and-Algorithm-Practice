class Solution {
public:
      void backtrack(int idx,vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&ans,long long sum){
        if(idx == candidates.size()){
            if(sum == target){
                ans.push_back(temp);
            }
              return;
        }
        if(sum > target) return;
        temp.push_back(candidates[idx]);
        sum +=candidates[idx];
        backtrack(idx,candidates,target,temp,ans,sum);
        temp.pop_back();
        sum-=candidates[idx];
        backtrack(idx+1,candidates,target,temp,ans,sum);
      }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        backtrack(0,candidates,target,temp,ans,0);
        return ans;
    }
};