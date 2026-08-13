class myStack {
  public:
       vector<int>arr;
        int i;
        int n ;
    myStack(int size) {
        arr.resize(size);
        n = size;
        i = -1;
    }

    bool isEmpty() {
        return i == -1;
    }

    bool isFull() {
        return i == n-1;
    }

    void push(int x) {
        if(isFull()) return;
         i++;
        arr[i] = x;
       
    }

    void pop() {
        if(isEmpty()) return;
        i--;
    }

    int peek() {
        if(isEmpty()) return -1;
        return arr[i];
    }
};