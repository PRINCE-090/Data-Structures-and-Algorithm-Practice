class Solution {
public:
   void findSubset(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&arr){
    if(idx == arr.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[idx]);
    findSubset(idx+1,temp,ans,arr);
    temp.pop_back();
    while(idx < arr.size()-1 &&arr[idx] == arr[idx+1]) idx++;
    findSubset(idx+1,temp,ans,arr);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>res;
        findSubset(0,temp,res,nums);
        return res;
    }
};