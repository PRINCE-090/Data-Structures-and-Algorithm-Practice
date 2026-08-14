class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {

  public:
   Node*head = NULL, *curr = NULL;
   int cnt = 0;
    myQueue() {
        // Initialize your data members
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int x) {
        Node*node = new Node(x);
        if(head == nullptr){
            head = node;
            curr = head;
        }
        else{
            curr->next = node;
            curr = curr->next;
        }
        cnt++;
    }

    void dequeue() {
        if(isEmpty()) return;
        head = head->next;
        cnt--;
    }

    int getFront() {
      if(isEmpty()) return -1;
      return head->data;
    }

    int size() {
       return cnt;
    }
};
