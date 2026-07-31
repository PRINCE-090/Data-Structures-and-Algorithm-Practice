/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *curr = head;
       Node*node = NULL;
        while(curr != NULL){
          node = curr->prev;
           curr->prev = curr->next;
           curr->next = node;
           curr = curr->prev;
        }
        return node->prev;
    }
};