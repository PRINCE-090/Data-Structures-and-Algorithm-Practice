class Solution {
  public:
    void stacksort(stack<int>&st1,stack<int>&st2){
        if(st1.empty()) return;
        int val ;
        if(!st1.empty()){
            val = st1.top();
            st1.pop();
            stacksort(st1,st2);
        }
        
        while(!st1.empty() &&val < st1.top()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return;
    }
    void sortStack(stack<int> &st) {
        stack<int>st2;
        stacksort(st,st2);
        
    }
};
