class Node{
public:
    int val;
    Node * next;
    Node *prev;
    Node(int value){
      val = value;
      next = nullptr;
      prev = nullptr;
    }
};
class ProductOfNumbers {
public:
    Node *dummy = new Node(-1);
    Node *head = dummy;
    Node *tail = dummy;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        Node *node = new Node(num);
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    
    int getProduct(int k) {
        Node *curr = tail;
        int i = 0, product = 1;
        while(i < k && curr != head){
            product *= curr->val;
            curr = curr->prev;
            i++;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */