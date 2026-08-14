/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {

  public:
  Node*head = NULL;
  int cnt = 0;
    myStack() {
        // Initialize your data members
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int x) {
        Node*node = new Node(x);
       if(head == NULL)
       {
           head = node;
       } else {
          node->next = head;
          head = node;
       }
       cnt++;
    }

    void pop() {
        if(head == NULL) return;
        head = head->next;
        cnt--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()) return -1;
        return head->data;
    }

    int size() {
       return cnt;
    }
};