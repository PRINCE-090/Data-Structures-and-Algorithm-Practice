class Solution {
  public:
    string preToPost(string &s) {
        int n = s.size();
        int i = n-1;
        stack<string>st;
        while(i >= 0){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] >='0'
            && s[i] <= '9'){
                st.push(string(1,s[i]));
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push(s1 + s2 + s[i]);
            }
            i--;
        }
        return st.top();
        
    }
};