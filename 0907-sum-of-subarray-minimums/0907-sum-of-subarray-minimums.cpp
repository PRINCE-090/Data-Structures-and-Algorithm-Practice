class Solution {
public:
    vector<int>findNSE(vector<int>arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i = arr.size()-1;i>= 0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findPSE(vector<int>arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i = 0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (int) (1e9 + 7);
        vector<int>NSE = findNSE(arr);
        vector<int>PSE = findPSE(arr);
        int n = arr.size(), total = 0;
        for(int i = 0;i<n;i++){
           int left = i - PSE[i];
           int right = NSE[i] - i; 
          total = (total + ((right*left*1LL*arr[i])%mod))%mod;
        }
        return total;
    }
};