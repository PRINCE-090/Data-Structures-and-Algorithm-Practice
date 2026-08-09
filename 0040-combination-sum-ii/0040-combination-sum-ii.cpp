class Solution {
public:
  void combination(int idx,int target,vector<int>&res,vector<vector<int>>&ans,vector<int>&arr,
 int n ){
    if(target == 0){
        ans.push_back(res);
        return;
    }
    for(int i = idx;i<n;i++){
        if(arr[i] > target) return;
        if(i > idx && arr[i] == arr[i-1]){
          continue;
        }
        res.push_back(arr[i]);
        combination(i+1,target-arr[i],res,ans,arr,n);
        res.pop_back();
    }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
        combination(0,target,res,ans,candidates,n);
        return ans;
    }
};