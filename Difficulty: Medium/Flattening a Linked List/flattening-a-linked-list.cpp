/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
   struct compare{
       bool operator()(Node *a , Node *b){
           return a->data > b->data;
       }
   };
    Node* flatten(Node* head) {
     if(head == NULL) return NULL;
     
     priority_queue<Node*,vector<Node*>,compare>pq;
     Node *temp = head;
     
     while(temp != NULL){
         pq.push(temp);
         temp = temp->next;
     }
     Node *dummy = new Node(-1);
     Node* tail = dummy;
     
     while(!pq.empty()){
         Node *curr = pq.top();
         pq.pop();
         
         if(curr->bottom != NULL){
             pq.push(curr->bottom);
         }
         
         tail->bottom = curr;
         tail = curr;
         
         curr->next = NULL;
     }
     tail->bottom = NULL;
     
     return dummy->bottom;
        
    }
};