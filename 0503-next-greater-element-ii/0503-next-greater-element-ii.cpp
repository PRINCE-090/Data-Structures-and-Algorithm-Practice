class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        bool check  = true;
        for(int i = 2*n-1;i>=0;i--){
            int newval = nums[i%n];
            while(!st.empty() && st.top() <= newval){
                 st.pop();
            }
            if(i < n){
            if(!st.empty()) ans[i] = st.top();     
            }
           
            st.push(newval);
        }
        return ans;
    }
};