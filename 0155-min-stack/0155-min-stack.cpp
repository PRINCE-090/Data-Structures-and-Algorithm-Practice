class MinStack {
public:
    stack<int>st,minst;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minst.push(value);
        }
        else{
            st.push(value);
            if(minst.top() >= st.top()){
                minst.push(st.top());
            }
        }
    }
    
    void pop() {
        if(st.top() == minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */