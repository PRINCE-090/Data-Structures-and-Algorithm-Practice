class Solution {
public:
     void performoperation(stack<int>&st,string operand){
        if(st.empty() || st.size() < 2) return ;
        int var1 = st.top();
        st.pop();
        int var2 = st.top();
        st.pop();
        if(operand == "+"){
            st.push(var2 + var1);
        }
       else if(operand == "*"){
            st.push(var2 * var1);
        }
       else if(operand == "-"){
            st.push(var2 - var1);
        }
       else if(operand == "/"){
            st.push(var2/var1);
        }
        return;
     }
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<int>st;
        string operand;
        for(int i = 0;i<n;i++){
            if(s[i] == "+" || s[i] == "-" ||s[i] == "*" ||s[i] == "/" ){
                operand = s[i];
                performoperation(st,operand);
            }
            else {
                st.push(stoi(s[i]));
            }
        }
       return st.top();
    }
};