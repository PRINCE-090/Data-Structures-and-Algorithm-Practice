class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>prefixsum(arr.size());
        prefixsum[0] = arr[0];
        for(int i = 1;i<arr.size();i++){
            prefixsum[i] = prefixsum[i-1] + arr[i]; 
        }
        vector<int>ans;
        for(int i = 0;i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];
            
            if(start - 1 < 0){
                ans.push_back(prefixsum[end]);
            }
            else{
                ans.push_back(prefixsum[end] - prefixsum[start-1]);
            }
        }
        return ans;
    }
};