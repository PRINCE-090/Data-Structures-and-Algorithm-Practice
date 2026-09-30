class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalsum = 0;
        for(int num : arr) totalsum += num;
        if(totalsum < diff || (totalsum - diff) %2 != 0) return 0;
        int target = (totalsum - diff)/2;
        vector<int>prev(target+1,0), curr(target+1,0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] <= target && arr[0] != 0) prev[arr[0]] = 1;
        
        for(int idx = 1;idx<n;idx++){
            for(int sum = 0;sum <= target;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(arr[idx] <= sum){
                    take = prev[sum - arr[idx]];
                }
                curr[sum] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];        

    }
};