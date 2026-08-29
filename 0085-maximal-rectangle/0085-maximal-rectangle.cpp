class Solution {
public:
    int histogram(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        int maxarea = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxarea = max(maxarea , arr[element] * (nse - pse -1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, arr[element] *(nse - pse -1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m= matrix[0].size();
        vector<vector<int>>prefixsum(n,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            int sum = 0;
            for(int i = 0;i<n;i++){
                if(matrix[i][j] == '1'){
                    sum += 1;
                } else{
                    sum = 0;
                }
                prefixsum[i][j] = sum;
            }
        }
        int maxrectangle = 0;
        for(int i = 0;i<n;i++){
            maxrectangle = max(maxrectangle,histogram(prefixsum[i]));
        }
        return maxrectangle;
    }
};