class Solution {
  public:
   void stackreverse(stack<int>&st,queue<int>q2){
       if(st.empty()) return;
       int val;
       if(!st.empty()){
           val = st.top();
           st.pop();
       }
       while(!st.empty()){
           q2.push(st.top());
           st.pop();
       }
       st.push(val);
       while(!q2.empty()){
           st.push(q2.front());
           q2.pop();
       }
       return;
   }
    void reverseStack(stack<int> &st) {
        queue<int>q2;
        stackreverse(st,q2);
        
    }
};