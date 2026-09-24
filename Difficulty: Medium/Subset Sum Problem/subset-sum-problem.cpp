class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool>prev(sum+1,false),curr(sum+1,false);
        for(int i = 0;i<n;i++) prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        prev[0] = true;
        
        for(int ind = 1;ind<n;ind++){
            curr[0] = true;
            for(int target = 1;target <= sum;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target){
                    take = prev[target-arr[ind]];
                }
                curr[target] = take || notTake;
            }
            prev = curr; 
        }
        return prev[sum];
    }
};