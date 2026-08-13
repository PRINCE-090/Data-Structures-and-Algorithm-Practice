class myQueue {
      vector<int>arr;
      int front,rear,size;
  public:
    myQueue(int n) {
       arr.resize(n);
       front = -1;
       rear = -1;
       size = n;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear+1)%size == front;
    }

    void enqueue(int x) {
        if(isFull()) return;
        if(isEmpty()) front = 0;
        
        rear = (rear+1)%size;
        arr[rear] = x;
    }

    void dequeue() {
        if(isEmpty()) return;
        if(front == rear){
            front = -1;
            rear = -1;
            return;
        }else{
           front = (front+1)%size;        
        }

    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
};