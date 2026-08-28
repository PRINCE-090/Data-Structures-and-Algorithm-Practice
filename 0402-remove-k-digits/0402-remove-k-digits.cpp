class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string res = "";
        stack<char>st;
        for(int i = 0;i<n;i++){
            char digit = num[i];
            while(!st.empty() && st.top() > digit && k > 0){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        while(!res.empty() && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";

        return res;
    }
};