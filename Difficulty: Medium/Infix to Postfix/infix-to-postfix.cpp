class Solution {
  public:
    int priority(char s){
        if(s == '+' || s == '-') return 1;
        else if(s == '/' || s == '*')return 2;
        else if(s == '^')return 3;
        else{
            return -1;
        }
    }
    string infixToPostfix(string& s) {
        int i = 0, n = s.size();
        stack<char>st;
        string ans;
        while(i < n){
            if((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' 
             && s[i] <= '9')){
                 ans += s[i];
             }
             else if(s[i] == '(')st.push('(');
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() &&  ((s[i] == '^' && priority(s[i]) < priority(st.top())
                || s[i] != '^' && priority(s[i]) <= priority(st.top())))){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            } 
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
