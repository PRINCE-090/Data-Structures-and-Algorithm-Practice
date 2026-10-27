class Solution {
  public:
    string postToPre(string s) {
       int n = s.size();
       int i = 0;
       stack<string>st;
       while(i<n){
           if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <='Z') || 
           (s[i] >= '0' && s[i] <= '9')){
               st.push(string(1,s[i]));
           }
           else{
               string s1 = st.top();
               st.pop();
               string s2 = st.top();
               st.pop();
               st.push(s[i] + s2 + s1);
           }
           i++;
       }
        return st.top();
    }
};