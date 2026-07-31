/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
      Node *node = new Node(x);
      if(head == nullptr){
          return node;
      }
      Node *curr = head;
      int i = 0;
      while(curr != nullptr && i <p){
          curr = curr->next;
          i++;
      }
      if(curr == nullptr){
          delete node;
          return head;
      }
      node->next = curr->next;
      node->prev = curr;
      if(curr->next != nullptr){
          curr->next->prev = node;
      }
      curr->next = node;
      return head;
    }
};