class Solution {
public:
   void findSubset(int idx,vector<int>&temp,set<vector<int>>&ans,vector<int>&arr){
    if(idx == arr.size()){
       // sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    temp.push_back(arr[idx]);
    findSubset(idx+1,temp,ans,arr);
    temp.pop_back();
    findSubset(idx+1,temp,ans,arr);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        set<vector<int>>ans;
        findSubset(0,temp,ans,nums);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};