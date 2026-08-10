class Solution {
  public:
   void subset(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&arr){
       if(idx == arr.size()){
           ans.push_back(temp);
           return;
       }
       temp.push_back(arr[idx]);
       subset(idx+1,temp,ans,arr);
       
       temp.pop_back();
       subset(idx+1,temp,ans,arr);
   }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>temp;
        vector<vector<int>>ans;
        subset(0,temp,ans,arr);
        return ans;
        
    }
};