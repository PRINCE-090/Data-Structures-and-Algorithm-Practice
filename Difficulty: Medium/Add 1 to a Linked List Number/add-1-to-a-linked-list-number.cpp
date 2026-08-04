/* Structure of linked list Node
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
     Node* reverseList(Node *head){
         Node*curr = head;
         Node*prev = NULL;
         while(curr != NULL){
             Node*front = curr->next;
             curr->next = prev;
             prev = curr;
             curr = front;
         }
         return prev;
     }
    Node* addOne(Node* head) {
       Node*newHead =  reverseList(head);
        int carry = 1;
        Node*prev = nullptr;
       Node*curr =newHead;
       while(curr != NULL){
           int sum = curr->data+carry;
           curr->data = sum%10;
           carry = sum/10;
           if(carry == 0) break;
           prev = curr;
           curr = curr->next;
       }
       if(carry > 0 && prev != NULL){
           prev->next = new Node(carry);
       }
       Node *newHEAD = reverseList(newHead);
       return newHEAD;
        
    }
};