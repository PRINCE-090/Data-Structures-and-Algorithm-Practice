class Solution {
  public:
    string postToInfix(string &s) {
        int i = 0,n= s.size();
        stack<string>st;
        while(i < n){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= '0' && s[i] <= '9')){
                st.push(string(1,s[i]));
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push("(" + s2 + s[i] + s1 + ")");
            }
            i++;
        }
        return st.top();
    }
};