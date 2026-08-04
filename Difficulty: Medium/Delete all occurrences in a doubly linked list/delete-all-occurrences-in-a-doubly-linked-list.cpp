/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        Node* dummy = new Node(-1);
        Node *temp = dummy,*curr = head;
        while(curr != NULL ){
            if(curr->data == x){
                curr = curr->next;
            }
            else{
                curr->prev = temp;
                temp->next = curr;
                temp = curr;
                curr = curr->next;
            }
        }
        temp->next = NULL;
        if(dummy->next != NULL){
            dummy->next->prev = NULL;
        }
        return dummy->next;
        
    }
};