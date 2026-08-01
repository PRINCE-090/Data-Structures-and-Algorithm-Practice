/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node* dummy3 = new Node(-1);
        Node *pointer0 = dummy1, *pointer1 = dummy2, *pointer2 = dummy3;
         Node*curr = head;
         while(curr != NULL){
             if(curr->data == 0){
                 pointer0->next = curr;
                 pointer0 = curr;
             }
             else if(curr->data == 1){
                 pointer1->next = curr;
                 pointer1 = curr;
             }
             else{
                 pointer2->next = curr;
                 pointer2 = curr;
             }
             curr = curr->next;
         }
         pointer0->next = (dummy2->next) ? dummy2->next : dummy3->next;
         pointer1->next = dummy3->next;
         pointer2->next = NULL;
         return dummy1->next;
    }
};