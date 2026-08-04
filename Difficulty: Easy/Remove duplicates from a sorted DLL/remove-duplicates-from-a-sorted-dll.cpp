/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node*temp = head;
        Node*curr = head->next;
        while(curr != nullptr){
            if(curr->data  == temp->data){
                curr  = curr->next;
            }
            else{
                curr->prev = temp;
                temp->next = curr;
                temp = curr;
                curr = curr->next;
            }
            
        }
        temp->next = nullptr;
        return head;
    }
};