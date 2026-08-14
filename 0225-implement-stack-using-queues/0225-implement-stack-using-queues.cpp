// using two queue
class MyStack {
public:
     queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(empty()) return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        if(empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


// using one queue

class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
       int i = 0;
       while(i < q.size()-1){
        q.push(q.front());
        q.pop();
        i++;
       }
    }
    
    int pop() {
       int val = q.front();
       q.pop();
       return val; 
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
