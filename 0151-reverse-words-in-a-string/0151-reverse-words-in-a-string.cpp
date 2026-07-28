class Solution {
public:
    string reverseWords(string s) {
       string res = "";
       stack<string>st;
       for(int i = 0;i<s.size();i++){
        if(s[i] == ' '){
            if(!res.empty()){
                st.push(res);
                res = "";
            }
        }
        else res += s[i];
       }
       if(!res.empty()){
        st.push(res);
       }
       string ans;
       while(st.size() != 1){
        ans += st.top()+" ";
        st.pop();
       }
         ans += st.top();
         return ans;
    }
};