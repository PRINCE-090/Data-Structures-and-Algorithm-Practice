class Solution {
  public:
    string preToInfix(string &s) {
       int n = s.size();
       int i = n-1;
       stack<string>st;
       while(i >= 0){
           if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
               st.push(string(1,s[i]));
           }
           else{
               string s1 = st.top();
               st.pop();
               string s2 = st.top();
               st.pop();
               string ans = "(" + s1 + s[i] + s2 + ")";
               st.push(ans);
           }
           i--;
       }
       return st.top();
        
    }
};