/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
       if(head == NULL) return false;
       if(head->data == key) return true;
       searchKey(head->next,key);
       
       
        
    }
};
