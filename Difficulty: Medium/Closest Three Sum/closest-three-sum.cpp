class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mingap = INT_MAX, ans = 0;
        for(int i = 0;i<n-2;i++){
            int left = i + 1;
            int right = n-1;
            while(left < right){
                int sum = arr[i] + arr[left] + arr[right];
                int curr_gap = abs(sum - target);
                    
                if(curr_gap < mingap){
                   mingap = curr_gap;
                    ans = sum;
                }
                else if(curr_gap == mingap){
                    ans = max(ans,sum);
                }
                
                if(sum < target) left++;
                else right--;
            }    
            
        }
        return ans;
        
    }
};